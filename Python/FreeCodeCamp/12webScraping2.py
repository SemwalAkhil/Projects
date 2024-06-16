import re
from bs4 import BeautifulSoup
import urllib.request

# url = input("Enter url : ")
url = r"https://quotes.toscrape.com/"
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html,"html.parser")
with open("13site.html","w",encoding="utf-8") as f:
    f.write(str(soup.prettify()))
# print(soup) # -> prints without indentation 
# print(soup.prettify()) # -> prints with indentation for easy reading
# print(soup.title) # -> prints entire tag 
# print(soup.title.name) # -> prints name of tag
# print(soup.title.string) # -> prints text in tag
# print(soup.title.parent.name) # -> prints parent tag of current tag
# print(soup.find_all('p'))

# extracting quotes and authors from the page
divs = soup.find_all('div')
quotes = {}
for div in divs:
    if (div["class"][0] == "quote"):
        spans = div.find_all("span")
        quote = spans[0].string
        author = spans[1].small.string
        # print(quote,"\n - ",author)
        quotes[quote] = author
print(quotes)


# tags = soup("tr")
# for tag in tags:
#     print(tag.get)


# fhand = urllib.request.urlopen(url)
# str = ""
# for line in fhand:
#     temp = line.decode().strip()
#     str += temp
#     lst = re.findall(r"<(.+?)>",str)
# for i in lst:
#     print(i)

# Retrieve all anchor tags

# tags = soup("a")
# for tag in tags:
#     print(tag.get("href",None))