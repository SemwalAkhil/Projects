# %%
from openai import OpenAI
import pandas as pd
import matplotlib.pyplot as plt
from fpdf import FPDF
import re
import os
from dotenv import load_dotenv

load_dotenv(".env.local")

KEY = os.getenv("OPENAI_KEY")

# Set up OpenAI API key
client = OpenAI(api_key=KEY)
# Load Excel data
def load_data(filepath):
    return pd.read_excel(filepath)

# Generate explanation for the scores using OpenAI API
def generate_explanation(scores):
    prompt = (
        "I have the scoring of students' answer sheets for the Aptitude test, which assesses multiple abilities, including Closure, Clerical, Mechanical, Numerical, Psychomotor, Reasoning, Spatial, and Verbal Ability scores. "
        f"Scores: {scores}. "
        "Please prepare a detailed report for each student following this specific format:\n"
        "1. Overview of Aptitude Test: A brief description of the test and its purpose in assessing aptitudes for career guidance.\n"
        "2. Individual Ability Scores: For each ability, include:\n"
        "   - The student's score.\n"
        "   - Interpretation of the score (e.g., high, average, or low aptitude).\n"
        "   - Explanation of what the ability measures and its relevance in real-life or career contexts.\n"
        "3. Career Recommendations: Suggest career options or fields of study that align with the student's aptitude profile.\n"
        "4. Personalized Advice: Offer actionable tips for skill enhancement and growth in areas where the student scores low or moderately.\n"
        "5. Conclusion: Provide an encouraging summary emphasizing the student's strengths and potential."
    )
    response = client.chat.completions.create(
    model="gpt-4o-mini",
    messages=[
            {"role": "system", "content": "You are a helpful assistant. Ensure the language is professional, empathetic, and easy for students and their parents to understand. Follow the specified format strictly."},
            {"role": "user", "content": prompt}
        ]
)
    return response.choices[0].message

# Generate a bar chart for scores
def generate_chart(scores, student_name):
    plt.figure(figsize=(8, 4))
    categories = list(scores.keys())
    values = list(scores.values())
    plt.bar(categories, values, color='skyblue')
    plt.title(f"Aptitude Test Scores for {student_name}")
    plt.xlabel("Categories")
    plt.ylabel("Scores")
    plt.xticks(rotation=45, ha='right')
    plt.tight_layout()
    chart_filename = f"{student_name}_chart.png"
    plt.savefig(chart_filename)
    plt.close()
    return chart_filename

def sanitize_text(text):
    return str(text).encode('latin-1', 'replace').decode('latin-1')  # Replace unsupported characters

# Function to clear # and ** characters from a string
def clean_string(text):
    return re.sub(r'([\#\*]|\n---\n)', '', text)

# Create PDF report using fpdf2
def create_report(count, student_name, student_class, gender, scores, explanation, chart_filename):
    # pdf = FPDF()
    class CustomPDF(FPDF):
        def header(self):
            # Add letterhead to every page
            self.image(r"D:\Kesri\Letters\letterHead6.png", x=0, y=0, w=210, h=297)
            self.set_y(50)  # Adjust to avoid overlap

        def footer(self):
            self.set_y(-15)  # Bottom margin
            self.set_font("DejaVu", size=8)
            self.cell(0, 10, f"Page {self.page_no()}", align="C")

    pdf = CustomPDF()
    pdf.set_auto_page_break(auto=True, margin=20)  # Increase margins on top and bottom
    pdf.add_page()
    """
    # Set the letterhead background
    letterhead_image = r"D:\Kesri\Letters\letterHead6.png"  # Path to the letterhead image
    pdf.image(letterhead_image, x=0, y=0, w=210, h=297)  # Full A4 size background
    """
    # Add Unicode-compatible font
    pdf.add_font("DejaVu", style="", fname="DejaVuSans.ttf", uni=True)
    pdf.add_font("DejaVu-Bold", style="B", fname="DejaVuSans-Bold.ttf", uni=True)

    # Add Title
    pdf.set_font("DejaVu", size=16)
    # pdf.ln(30)  # Ensure text starts below the letterhead header
    pdf.cell(0, 10, "Aptitude Test Report For Career Guidance", ln=True, align='C')
    pdf.ln(10)

    # Add Student Details
    pdf.set_font("DejaVu", size=12)
    pdf.cell(0, 10, f"Name: {student_name}", ln=True)
    pdf.cell(0, 10, f"Class: {student_class}", ln=True)
    pdf.cell(0, 10, f"Gender: {gender}", ln=True)
    pdf.ln(10)

    # Add Chart
    pdf.image(chart_filename, x=15, y=100, w=180)
    pdf.ln(80)  # Ensure space after the chart

    # Add Explanation
    pdf.set_font("DejaVu", size=14)
    pdf.cell(0, 10, "Explanation of Scores:", ln=True)
    pdf.set_font("DejaVu", size=12)
    pdf.multi_cell(0, 10, clean_string(explanation))

    # Save PDF
    report_filename = f"{count}_{student_name}_class_{student_class}_DBDA_Report.pdf"
    pdf.output(report_filename)
    return report_filename

# %%

filepath = r"D:\Kesri\Results\sample.xlsx"  # Path to the uploaded file
data = load_data(filepath)
count = 1
# redo = [2,4,16,17,59,67,89,108,109,145,150,155,167,169,178,193]
for _, row in data.iterrows():
    # if (count not in redo):
    #     count += 1
    #     continue
    student_name = row['Name']  # Assuming there's a 'Name' column
    student_class = row.get('Class', 'Unknown')  # Assuming there's a 'Class' column
    gender = row.get('Sex', 'Unknown')  # Assuming there's a 'Gender' column
    scores = {col: row[col] for col in data.columns if col not in ['Name', 'Class', 'Sex']}
    explanation = generate_explanation(scores).content
    # print(explanation)
    # %%
    # explanation = clean_string(explanation)
    chart_filename = generate_chart(scores, student_name)
    report_filename = create_report(count, student_name, student_class, gender, scores, explanation, chart_filename)
    count += 1
    print(f"Generated report: {report_filename}")

