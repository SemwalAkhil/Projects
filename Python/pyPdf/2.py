import json
import re
from fpdf import FPDF, HTMLMixin  # Import HTMLMixin

def sanitize_text(text):
    return str(text).encode('latin-1', 'replace').decode('latin-1')  # Replace unsupported characters

# Create a custom PDF class that includes HTML rendering capabilities
class MyFPDF(FPDF, HTMLMixin):
    pass

def create_chat_pdf(json_data_or_path, output_filename="chat_output_formatted.pdf"):
    """
    Creates a PDF document from chat data in a JSON structure using FPDF and HTMLMixin
    to handle basic formatting like **bold**.

    Args:
        json_data_or_path (dict or str): The JSON data (dictionary) or a file path
                                         to the JSON file.
        output_filename (str): The desired name for the output PDF file.
    """

    # --- Load the JSON data ---
    data = None
    if isinstance(json_data_or_path, str):
        try:
            with open(json_data_or_path, 'r', encoding='utf-8') as f:
                data = json.load(f)
        except FileNotFoundError:
            print(f"Error: JSON file not found at {json_data_or_path}")
            return
        except json.JSONDecodeError:
            print(f"Error: Could not decode JSON from {json_data_or_path}")
            return
    elif isinstance(json_data_or_path, dict):
        data = json_data_or_path
    else:
        print("Error: Input must be a dictionary or a file path string.")
        return

    if not data:
        print("Error: No data loaded.")
        return

    # --- Extract required information ---
    title = data.get("title", "Chat Conversation")
    messages = data.get("messages", [])
    system_instruction = data.get("systemInstruction", {}).get("parts", [{}])[0].get("text", "No system instruction provided.")

    if not messages:
        print("Warning: No messages found in the JSON data.")

    # --- Create PDF using custom FPDF class with HTML support ---
    pdf = MyFPDF('P', 'mm', 'A4')  # Portrait, millimeters, A4 size
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()

    # Set initial font
    pdf.set_font('Arial', '', 12)

    # Add Title
    pdf.set_font('Arial', 'B', 16)
    pdf.multi_cell(0, 10, title, 0, 'C')
    pdf.ln(10)

    # Add System Instruction
    system_instruction_html = convert_markdown_to_html(system_instruction)
    pdf.set_font('Arial', 'B', 10)
    pdf.cell(0, 6, "System Instruction:", 0, 1)
    pdf.write_html(system_instruction_html)
    pdf.ln(10)

    # Add Messages
    pdf.set_font('Arial', '', 10)

    for i, message in enumerate(messages):
        author = message.get("author", "Unknown")
        content_parts = message.get("content", {}).get("parts", [])
        text = ""
        if content_parts:
            text = content_parts[0].get("text", "")

        if text:
            if i > 0:
                pdf.ln(5)

            pdf.set_font('Arial', 'B', 10)
            pdf.cell(0, 6, f"{author.capitalize()}:", 0, 1)

            message_html = convert_markdown_to_html(text)
            pdf.write_html(message_html)

    # --- Output the PDF ---
    try:
        pdf.output(output_filename)
        print(f"PDF created successfully: {output_filename}")
    except Exception as e:
        print(f"Error writing PDF file: {e}")

def convert_markdown_to_html(text):
    """
    Converts simple markdown like **bold** to HTML <b>bold</b>
    and escapes potential HTML entities.
    Handles bolding across multiple lines if needed.
    """
    if not isinstance(text, str):
        return ""

    escaped_text = sanitize_text(text.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;'))

    html_text = re.sub(r'\>.*?(\*).*\<',r'-',re.sub(r'\n', r'<br>', re.sub(r'\*\*(.*?)\*\*', r'<b>\1</b>', escaped_text, flags=re.DOTALL), flags=re.DOTALL),flags=re.DOTALL)
    with open("after.txt", "w", encoding="utf-8") as file:
        file.write(html_text)

    return html_text

# --- Example Usage ---
if __name__ == "__main__":
    json_file_path = r"D:\Downloads\SPM.json"
    create_chat_pdf(json_file_path, "spm_chat_from_file.pdf")
