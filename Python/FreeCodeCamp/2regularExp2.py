import re

str = "From abCdef@ghi.jkl Sat Jan 5 09:14:56 2008"
str2 = "Received $10.00 for cookies"
pattern1 = r"^From ([A-z]+)" # extracting username
pattern2 = r"^From [A-z]+"
pattern3 = r"[A-z]+@"

# extracting hostname from the string
pattern4 = r"^From \S+@([A-z]+.[A-z]+)"
pattern5 = r"@([^ ]*)" # [^ ] stands for non-blank character
pattern6 = r"@(\S*)"
pattern7 = r"^From \S*@(\S*)"
pattern8 = r"^From .*@(\S*)"
# the patterns with from only match the first line

pattern9 = r"([0-9:]+)" # extract integers including time string 
pattern10 = r"\$[0-9.]+" # extract $ sign and following integers

# text = re.findall(pattern1,str)
# print(text)

# text = re.findall(pattern2,str)
# print(text)

# text = re.findall(pattern3,str)
# text = re.findall(r"[A-z]+",text[0])
# print(text)

# text = re.findall(pattern4,str)
# print(text)

# atpos = str.find('@') # print index of @
# print(atpos)
# sppos = str.find(' ',atpos) # print index of first whitespace after @
# print(sppos)
# host = str[atpos+1 : sppos] # extract string between the given index
# print(host)

# Alternate way to extract hostname
# words = str.split()
# email = words[1]
# pieces = email.split("@")
# print(pieces[1])

# text = re.findall(pattern5,str)
# print(text)

# text = re.findall(pattern6,str)
# print(text)

# text = re.findall(pattern7,str)
# print(text)

# text = re.findall(pattern8,str)
# print(text)

# text = re.findall(pattern9,str)
# print(text)

text = re.findall(pattern10,str2)
print(text)