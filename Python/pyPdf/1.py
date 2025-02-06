import camelot
import pandas as pd

# Path to your PDF file
pdf_path = r"D:\Downloads\Haryana_merged.pdf"

# Extract tables using Camelot
tables = camelot.read_pdf(pdf_path, pages='all', flavor='stream')  # Use 'stream' or 'lattice' based on PDF structure

# Check if tables were found
if not tables:
    print("No tables found in the PDF.")
else:
    # Combine all extracted tables into one DataFrame
    combined_data = pd.concat([table.df for table in tables], ignore_index=True)
    
    # Save to Excel
    output_path = "Schools_List_Camelot.xlsx"
    combined_data.to_excel(output_path, index=False)
    print(f"Extracted table saved to {output_path}.")
