import ocrmypdf

input_pdf = r"D:\Downloads\Elements-of-Discrete-Mathematics_-2e-_Chung-Laung-Liu_-_Z-Library_.pdf"      # Scanned PDF
output_pdf = "temp_scanned.pdf"   # Searchable PDF

# OCR the PDF
ocrmypdf.ocr(
    input_pdf,
    output_pdf,
    language="eng",          # You can add +hin for Hindi etc. e.g., "eng+hin"
    deskew=True,
)

print("✅ OCR Completed! Searchable PDF saved as:", output_pdf)
