def check_any_digit_match(group, pattern):
    """
    Check if any line in the group matches the last digit of the pattern.
    """
    for i, line in enumerate(group):
        # Get the last digit of the number in each line
        last_digit = int(line.split()[-1][-1])  # Extract the last digit of the number
        if last_digit == pattern[i]:
            return True  # At least one match found
    return False  # No match found for this group

def main():
    # Input and output file paths
    input_file_path = 'input.txt'
    output_file_path = 'output.txt'
    pattern = [2, 3, 4, 8, 9, 0, 4, 5, 6]
    groups = []

    # Read lines from the input file
    with open(input_file_path, 'r') as input_file:
        lines = [line.strip() for line in input_file.readlines()]
        # print(len(lines)) # 2304 lines

    # Pattern to match last digits (for 9 lines in each group)
    # Group the lines into 3 sets (each group containing 9 lines)
    # groups = [lines[:9], lines[9:18], lines[18:27]]   # Problem line -> took only 3 groups
    for i in range(0,len(lines),9):
        # print(i,i+8)
        groups += [lines[i:i+9]]                            # now makes group correctly
    
    # print(len(groups))
    # print(groups) # check groups
    
    # Open the output file in write mode
    with open(output_file_path, 'w') as output_file:

        # Check each group
        for group_number, group in enumerate(groups, 1):

            # debug code to check upto 10 groups
            # if group_number == 10:
            #     break
            # print(group_number,group)\
            
            if check_any_digit_match(group, pattern):
                output_file.write(f"Group {group_number} match\n")  # Only write if group matches

if __name__ == "__main__":
    main()
