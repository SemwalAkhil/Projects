from bs4 import BeautifulSoup
import urllib.request

url = input("Enter : ")
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html,"html.parser")

# Retrieve all anchor tags

tags = soup("a")
for tag in tags:
    print(tag.get("href",None))