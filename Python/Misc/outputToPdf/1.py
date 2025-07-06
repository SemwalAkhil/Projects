"""---------------------------------------------------------------------------------------------"""

import cv2
import os
from img2pdf import convert
import re
from pypdf import PdfReader, PdfWriter, PageObject

# Input and output directories
input_dir = r"C:\Users\Akhil Semwal\OneDrive\Desktop\linuxOut"
output_dir = r"C:\Users\Akhil Semwal\OneDrive\Desktop\linuxOut\out"

# Ensure output directory exists
os.makedirs(output_dir, exist_ok=True)


def custom_sort_key(filename):
    """Extracts numeric parts from filenames for sorting."""
    match = re.match(r"(\d+)(?:\.(\d+))?", filename)
    if match:
        main_number = int(match.group(1))
        sub_number = int(match.group(2)) if match.group(2) else 0  # Sub-number defaults to 0
        return (main_number, sub_number)
    return (float('inf'), float('inf'))  # Place unrecognized files at the end


def combine_pages_into_one(pdf_path):
    """Combine multiple pages of a PDF into a single A4 page."""
    reader = PdfReader(pdf_path)
    num_pages = len(reader.pages)

    # if num_pages == 1:
    #     return reader.pages  # Return as is if only one page

    a4_width, a4_height = 595, 842  # A4 portrait dimensions in points
    new_page = PageObject.create_blank_page(width=a4_width, height=a4_height)

    if num_pages == 1:
        rows, cols = 1,1
    elif num_pages == 2:
        rows, cols = 1,2
    else:
        rows, cols = 2,2
    
    cell_width, cell_height = a4_width / cols, a4_height / rows

    for i, page in enumerate(reader.pages[:rows * cols]):
        width = page.mediabox.width
        height = page.mediabox.height

        scale_factor = min(cell_width / width, cell_height / height)
        page.scale_by(scale_factor)

        x_offset = (cell_width - width * scale_factor) / 2 + (i % cols) * cell_width
        y_offset = (cell_height - height * scale_factor) / 2 + (i // cols) * cell_height

        new_page.merge_translated_page(page, tx=x_offset, ty=y_offset)

    return [new_page]

def combine_pdfs(input_dir, output_path):
    """Combines multiple PDFs into a single PDF, keeping them in portrait mode and ensuring all pages of each PDF stay as a single page."""
    pdf_writer = PdfWriter()
    # a4_width, a4_height = 595, 842  # A4 portrait dimensions in points
    dirs = sorted(os.listdir(input_dir),key=custom_sort_key)
    for filename in dirs:
        if filename.endswith(".pdf") and (not filename.startswith("combined")):
            # print("->",filename)
            pdf_path = os.path.join(input_dir, filename)
            try:
                combined_pages = combine_pages_into_one(pdf_path)
                for page in combined_pages:
                    pdf_writer.add_page(page)
            except Exception as e:
                print(f"Error processing PDF '{filename}': {e}")
    
    with open(output_path, "wb") as output_file:
        pdf_writer.write(output_file)


# Dictionary to group images by integer part of filename
image_groups = {}
dirs = sorted(os.listdir(input_dir),key=custom_sort_key)
for filename in dirs:
    if filename.endswith((".png", ".jpg", ".jpeg")):
        # print("->>",filename)
        match = re.match(r"(\d+)", filename)  # Extract integer part
        if match:
            integer_part = match.group(1)
            # print(f"GROUPED: \nimg {match}\n{filename}")
            image_groups.setdefault(integer_part, []).append(os.path.join(input_dir, filename))
        else:
            print(f"Warning: Filename '{filename}' does not match the expected pattern. Skipping.")

# Process each group and create a PDF
for group_name, image_paths in image_groups.items():
    inverted_images = []
    for img_path in image_paths:
        try:
            img = cv2.imread(img_path, cv2.IMREAD_GRAYSCALE)
            
            if img is None:
                print(f"Warning: Could not read image {img_path}")
                continue
            inverted_img = cv2.bitwise_not(img)
            output_path = os.path.join(output_dir, os.path.basename(img_path))  # Save inverted image
            cv2.imwrite(output_path, inverted_img)
            inverted_images.append(output_path)
            # print(f"PROCESSED : \n{group_name}\n{img_path}\n{output_path}")
        except Exception as e:
            print(f"Error processing image {img_path}: {e}")

    pdf_output_path = os.path.join(output_dir, f"{group_name}.pdf")
    try:
        pdf_bytes = convert(inverted_images)
        if pdf_bytes:
            with open(pdf_output_path, "wb") as f:
                f.write(pdf_bytes)
    except Exception as e:
        print(f"Error creating PDF for group {group_name}: {e}")

print("Processing and PDF creation complete. Check the output folder.")


pdf_output_path = os.path.join(output_dir, "combined.pdf")
combine_pdfs(output_dir, pdf_output_path)
print(f"Combined PDF created at: {pdf_output_path}")

