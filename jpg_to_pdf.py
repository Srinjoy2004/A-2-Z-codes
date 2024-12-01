from tkinter import Tk, filedialog
from PIL import Image

def jpg_to_pdf():
    """
    Converts selected JPG images to a single PDF.
    Allows users to manually select files and save the output.
    """
    try:
        # Initialize tkinter and hide the main window
        root = Tk()
        root.withdraw()
        root.update()  # Update the GUI before opening file dialog

        # Ask user to select multiple JPG files
        file_paths = filedialog.askopenfilenames(
            title="Select JPG files",
            filetypes=[("JPG Files", "*.jpg"), ("JPEG Files", "*.jpeg"), ("All Files", "*.*")]
        )

        if not file_paths:
            print("No files selected. Exiting.")
            return

        # Open and convert the first image to RGB
        first_image = Image.open(file_paths[0]).convert('RGB')

        # Open and convert the remaining images
        other_images = [Image.open(path).convert('RGB') for path in file_paths[1:]]

        # Ask user to choose the output file location and name
        output_path = filedialog.asksaveasfilename(
            title="Save PDF as",
            defaultextension=".pdf",
            filetypes=[("PDF Files", "*.pdf")]
        )

        if not output_path:
            print("No output file selected. Exiting.")
            return

        # Save all selected images into a single PDF
        first_image.save(output_path, save_all=True, append_images=other_images)
        print(f"PDF successfully created at {output_path}")

    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function
jpg_to_pdf()
