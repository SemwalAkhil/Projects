from flask import Flask, render_template_string, request, send_file, session
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from PIL import Image
import io
import csv
import datetime
import os
import secrets
import uuid
import logging

# Configure logging
logging.basicConfig(level=logging.INFO)

app = Flask(__name__)
app.secret_key = secrets.token_hex(16)
app.config['RESULTS_DIR'] = os.path.join(os.getcwd(), 'results')
os.makedirs(app.config['RESULTS_DIR'], exist_ok=True)

# Server-side session storage
sessions = {}

MOBILE_HTML = '''
<!DOCTYPE html>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body {font-family: Arial; margin: 20px;}
        .form-group {margin-bottom: 15px;}
        select, input {width: 100%; padding: 12px; margin: 8px 0; border: 1px solid #ccc; box-sizing: border-box;}
        button {background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;}
        .loader {border: 5px solid #f3f3f3; border-radius: 50%; border-top: 5px solid #3498db; width: 50px; height: 50px; animation: spin 2s linear infinite; margin: 20px auto;}
        @keyframes spin {0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); }}
        .error {color: red; margin: 10px 0;}
        .step-indicator {margin: 20px 0; font-weight: bold;}
    </style>
    <script>
        function showLoader() {
            document.getElementById('loader').style.display = 'block';
            document.getElementById('form-container').style.display = 'none';
        }
    </script>
</head>
<body>
    <div id="form-container">
        <h2>University Result Scraper</h2>
        <div class="step-indicator">
            {% if current_step is defined and total_steps is defined %}
            Step {{ current_step + 1 }} of {{ total_steps }}
            {% endif %}
        </div>
        {% if error %}<div class="error">{{ error }}</div>{% endif %}
        <form method="POST" onsubmit="showLoader()">
            {% for field in form_fields %}
            <div class="form-group">
                <label>{{ field.label }}</label>
                <select name="{{ field.name }}" required>
                    <option value="">Select {{ field.label }}</option>
                    {% for option in field.options %}
                    <option value="{{ option.value }}">{{ option.text }}</option>
                    {% endfor %}
                </select>
            </div>
            {% endfor %}
            {% if show_roll_input %}
            <div class="form-group">
                <label>Start Roll No:</label>
                <input type="number" name="start_roll" required>
            </div>
            <div class="form-group">
                <label>End Roll No:</label>
                <input type="number" name="end_roll" required>
            </div>
            {% endif %}
            <button type="submit">
                {% if show_roll_input %}Get Results{% else %}Next Step{% endif %}
            </button>
        </form>
    </div>
    <div id="loader" class="loader" style="display: none;"></div>
    {% if result_links %}
    <h3>Download Results:</h3>
    {% for link in result_links %}
    <a href="{{ link.url }}" class="result-link">{{ link.text }}</a>
    {% endfor %}
    {% endif %}
</body>
</html>
'''

class BrowserSession:
    def __init__(self):
        self.driver = self.init_driver()
        self.current_step = 0
        self.form_steps = [
            {'name': 'session', 'label': 'Academic Session', 'type': 'link', 
             'locator': (By.CLASS_NAME, 'MainLink')},
            {'name': 'course', 'label': 'Course', 'type': 'select', 
             'locator': (By.NAME, "ctl00$cph1$ddlCourse")},
            {'name': 'class', 'label': 'Class', 'type': 'select', 
             'locator': (By.NAME, "ctl00$cph1$ddlClass")},
            {'name': 'semester', 'label': 'Semester', 'type': 'link', 
             'locator': (By.CSS_SELECTOR, "#ctl00_cph1_tbLinks a")},
            {'name': 'exam', 'label': 'Exam Type', 'type': 'select', 
             'locator': (By.ID, "ctl00_cph1_ddlCollCode")}
        ]

    def init_driver(self):
        options = webdriver.ChromeOptions()
        options.add_argument("--headless")
        options.add_argument("--disable-gpu")
        options.add_argument("--no-sandbox")
        options.add_argument("--log-level=3")
        driver = webdriver.Chrome(options=options)
        driver.get("https://results.puexam.in/")
        WebDriverWait(driver, 20).until(
            EC.presence_of_element_located((By.CLASS_NAME, 'MainLink'))
        )
        return driver

    def reset(self):
        """Properly reset the browser session"""
        try:
            if self.driver:
                self.driver.quit()
        except Exception as e:
            logging.error(f"Error quitting driver: {str(e)}")
        finally:
            self.__init__()  # Reinitialize the session

    def __del__(self):
        """Destructor to ensure driver cleanup"""
        try:
            if self.driver:
                self.driver.quit()
        except:
            pass

@app.route('/', methods=['GET', 'POST'])
def main():
    session_id = None
    try:
        session_id = session.get('session_id')
        
        if not session_id or session_id not in sessions:
            session_id = str(uuid.uuid4())
            session['session_id'] = session_id
            sessions[session_id] = BrowserSession()
            logging.info(f"New session created: {session_id}")

        browser_session = sessions[session_id]
        
        if request.method == 'POST':
            if browser_session.current_step >= len(browser_session.form_steps):
                return process_results(browser_session)
            return handle_post(browser_session)
            
        return handle_get(browser_session)
        
    except Exception as e:
        logging.error(f"Main route error: {str(e)}")
        if session_id and session_id in sessions:
            try:
                sessions[session_id].reset()
                current_step = sessions[session_id].current_step
            except:
                current_step = 0
                del sessions[session_id]
        else:
            current_step = 0
            
        return render_template_string(
            MOBILE_HTML,
            error="Session error. Please refresh the page.",
            form_fields=[],
            current_step=current_step,
            total_steps=5,
            show_roll_input=False
        )

def handle_get(browser_session):
    try:
        form_fields = []
        steps = browser_session.form_steps
        
        # Only show current step's field
        current_step = browser_session.current_step
        if current_step < len(steps):
            step = steps[current_step]
            
            if step['type'] == 'link':
                elements = WebDriverWait(browser_session.driver, 15).until(
                    EC.presence_of_all_elements_located(step['locator'])
                )
                options = [{'text': e.text, 'value': i} for i, e in enumerate(elements)]
            else:
                element = WebDriverWait(browser_session.driver, 15).until(
                    EC.presence_of_element_located(step['locator'])
                )
                options = [{'text': o.text, 'value': i} for i, o in 
                         enumerate(element.find_elements(By.TAG_NAME, 'option'))
                         if o.text.strip() and o.get_attribute('value')]
            
            form_fields.append({
                'name': step['name'],
                'label': step['label'],
                'options': options
            })

        return render_template_string(
            MOBILE_HTML,
            form_fields=form_fields,
            current_step=current_step,
            total_steps=len(steps),
            show_roll_input=current_step >= len(steps) - 1
        )
    
    except Exception as e:
        logging.error(f"GET handler error: {str(e)}")
        return render_template_string(
            MOBILE_HTML,
            error="Failed to load form options",
            form_fields=[],
            current_step=0,
            total_steps=5,
            show_roll_input=False
        )

def handle_post(browser_session):
    try:
        form_data = request.form.to_dict()
        current_step = browser_session.current_step
        
        if current_step >= len(browser_session.form_steps):
            raise IndexError("Form completed - invalid step progression")

        step_config = browser_session.form_steps[current_step]
        
        # Validate selection exists
        if step_config['name'] not in form_data:
            raise ValueError(f"Missing {step_config['name']} selection")

        # Process selection
        if step_config['type'] == 'link':
            elements = WebDriverWait(browser_session.driver, 15).until(
                EC.presence_of_all_elements_located(step_config['locator'])
            )
            selected_idx = int(form_data[step_config['name']])
            elements[selected_idx].click()
        else:
            element = WebDriverWait(browser_session.driver, 15).until(
                EC.presence_of_element_located(step_config['locator'])
            )
            select_idx = int(form_data[step_config['name']])
            element.find_elements(By.TAG_NAME, 'option')[select_idx].click()

        # Wait for page update
        WebDriverWait(browser_session.driver, 15).until(
            EC.presence_of_element_located(
                browser_session.form_steps[current_step + 1]['locator']
            )
        )
        
        browser_session.current_step += 1
        logging.info(f"Advanced to step {browser_session.current_step}")

        return main()

    except Exception as e:
        logging.error(f"POST handler error: {str(e)}")
        return render_template_string(
            MOBILE_HTML,
            error="Please make a valid selection and try again",
            form_fields=[],
            current_step=browser_session.current_step if browser_session else 0,
            total_steps=len(browser_session.form_steps) if browser_session else 5,
            show_roll_input=False
        )

def process_results(browser_session):
    try:
        start_roll = int(request.form['start_roll'])
        end_roll = int(request.form['end_roll'])
        session_id = session['session_id']
        session_dir = os.path.join(app.config['RESULTS_DIR'], session_id)
        os.makedirs(session_dir, exist_ok=True)
        results = []

        for roll in range(start_roll, end_roll + 1):
            try:
                # Input roll number
                roll_input = WebDriverWait(browser_session.driver, 10).until(
                    EC.presence_of_element_located((By.ID, "ctl00_cph1_txtRollNo"))
                )
                roll_input.clear()
                roll_input.send_keys(str(roll))
                
                # Submit form
                submit = browser_session.driver.find_element(By.ID, "ctl00_cph1_btnShowResult")
                submit.click()
                
                # Wait for results
                WebDriverWait(browser_session.driver, 10).until(
                    EC.presence_of_element_located((By.ID, "ctl00_cph1_lblCName"))
                )
                
                # Capture data
                name = browser_session.driver.find_element(By.ID, "ctl00_cph1_lblCName").text.strip()
                total_score = browser_session.driver.find_element(By.ID, "ctl00_cph1_lblMarks").text.strip()
                
                # Save screenshot
                img_path = os.path.join(session_dir, f"result_{roll}.png")
                Image.open(io.BytesIO(browser_session.driver.get_screenshot_as_png())).save(img_path)
                
                results.append({'roll': roll, 'name': name, 'score': total_score, 'image': img_path})
                
                # Navigate back
                browser_session.driver.back()
                WebDriverWait(browser_session.driver, 10).until(
                    EC.presence_of_element_located((By.ID, "ctl00_cph1_txtRollNo"))
                )

            except Exception as e:
                logging.error(f"Error processing roll {roll}: {str(e)}")
                continue

        # Generate CSV
        csv_filename = os.path.join(session_dir, f"results_{datetime.datetime.now().strftime('%Y%m%d%H%M%S')}.csv")
        with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(['Roll No', 'Name', 'Total Score'])
            for result in results:
                writer.writerow([result['roll'], result['name'], result['score']])

        # Prepare download links
        links = [{'text': 'Download CSV', 'url': f'/download/{session_id}/{os.path.basename(csv_filename)}'}]
        links += [{'text': f'Result {r["roll"]}', 'url': f'/download/{session_id}/{os.path.basename(r["image"])}'} for r in results]

        # Cleanup
        browser_session.reset()
        del sessions[session_id]
        
        return render_template_string(MOBILE_HTML, result_links=links)

    except Exception as e:
        logging.error(f"Processing error: {str(e)}")
        # In all error return statements, add:
        return render_template_string(
            MOBILE_HTML,
            error="Your error message",
            form_fields=[],
            current_step=0,
            total_steps=5,
            show_roll_input=False
        )

@app.route('/favicon.ico')
def favicon():
    return '', 204

@app.route('/download/<session_id>/<filename>')
def download_file(session_id, filename):
    try:
        file_path = os.path.join(app.config['RESULTS_DIR'], session_id, filename)
        if not os.path.exists(file_path):
            raise FileNotFoundError(f"File {filename} not found")
        return send_file(file_path, as_attachment=True)
    except Exception as e:
        logging.error(f"Download error: {str(e)}")
        return "File not found", 404

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, threaded=True)