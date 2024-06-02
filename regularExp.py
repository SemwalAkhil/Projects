# ---------------------------------------------------------------------------

# used for complex seraches without relying on loops and "in" operator

# In computing, a regular expression, also referred to as "regex" or "regexp", provides a concise and flexible means for matching strings of text, such as particular characters, words, or patterns of characters. A regular expression is written in a formal language that can be interpreted by a regular expression processor.

# ---------------------------------------------------------------------------

import re

pattern1 = "abcd"
pattern2 = r"[A-Z]+orem" # Word ending with orem and starting with any character from A-Z
                         # + stands for one or more occurences
pattern3 = r"[A-Z]orem"
pattern4 = r"Lorem"      # all lorem in string
pattern5 = r"^Lorem"     # lorem which is at beginning of the string
pattern6 = r"^Lorem.*College"   # looks for lorem at start of string
                                # . specify any character between given two characters
                                # * star specify the previous character (in this case any character) any number of times
                                # college is the end of string
pattern7 = r"^L\S+m"     # Looks for "L" in beginning of string
                         # "\S" looks for non whitespace characters
                         # "+" specify any number of previous character (in this case - non whitespace character )
                         # last character must be "m" before reaching any whitespace
pattern8 = r"Lorem\s+Ipsum"
text = '''Lorem Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney CLorem College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" (The Extremes of Good and Evil) by Cicero, written in 45 BC. Lorem This Sorem book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, "Lorem ipsum dolor sit amet..", comes from a line in section 1.10.32.

The standard chunk of Lorem               Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from "de Finibus Borem Bonorum et Malorum" by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham.

There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined Gorem chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.'''


# ---------------------------------------------------------------------------

# You can use re.search() to see if a string matches a regular expression, similar to using the find() method for strings

# You can use re.findall() to extract portions of a string that match your regular expression, similar to a combination of find() and slicing: var[5:10]

# ---------------------------------------------------------------------------

# match = re.search(pattern1,text)
# print(match)

# match = re.search(pattern2,text) # shows first occurence only
# print(match)

# match = re.findall(pattern2,text)
# print(match)

# match = re.findall(pattern3,text) # list all occurences
# print(match)

# match = re.finditer(pattern3,text) # gives an iterator object
# print(match,"\n")
# print(type(match),"\n")
# for m in match:
#     print(m)

# match = re.findall(pattern4,text)
# print(match)

# match = re.findall(pattern5,text)
# print(match)

# match = re.findall(pattern6,text)
# print(match)

# match = re.findall(pattern7,text)
# print(match)

match = re.findall(pattern8,text)
print(match)