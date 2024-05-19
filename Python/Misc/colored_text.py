# ANSI escape codes for text colors
red_text = "\033[91m"
green_text = "\033[92m"
blue_text = "\033[94m"
reset_text = "\033[0m"  # Reset color to default
name="\033[95mName"
print(name)
# Print text in different colors
print(f"{red_text}This is red text{reset_text}")
print(f"{green_text}This is green text{reset_text}")
print(f"{blue_text}This is blue text{reset_text}")

'''
Red: "\033[91m"
Green: "\033[92m"
Yellow: "\033[93m"
Blue: "\033[94m"
Magenta: "\033[95m"
Cyan: "\033[96m"
Light Gray: "\033[97m"
Dark Gray: "\033[90m"
Light Red: "\033[91m"
Light Green: "\033[92m"
Light Yellow: "\033[93m"
Light Blue: "\033[94m"
Light Magenta: "\033[95m"
Light Cyan: "\033[96m"
White: "\033[97m"

check more at 
ANSI escape code - Wikipedia
'''