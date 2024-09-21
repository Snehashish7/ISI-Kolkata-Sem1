import sys

def add_prefix_to_string_in_file(filename, target_string, prefix):
    try:
        # Read the content of the file
        with open(filename, 'r') as file:
            content = file.read()
        
        # Replace all occurrences of the target string with the prefixed string
        modified_content = content.replace(target_string, prefix + target_string)
        
        # Write the modified content back to the file
        with open(filename, 'w') as file:
            file.write(modified_content)
        
        print("File has been updated successfully.")
        
    except FileNotFoundError:
        print(f"Error: The file '{filename}' does not exist.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Check if the correct number of command-line arguments are provided
    if len(sys.argv) != 4:
        print("Usage: ./prog <input_filename> <string> <prefix>")
    else:
        input_filename = sys.argv[1]
        target_string = sys.argv[2]
        prefix = sys.argv[3]
        
        add_prefix_to_string_in_file(input_filename, target_string, prefix)
