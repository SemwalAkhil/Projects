from bs4 import BeautifulSoup
import urllib.request
from googlesearch import search
import re

def getHtml(url:str):
    fhand = urllib.request.urlopen(url)
    html_doc = ""
    for line in fhand:
        html_doc += line.decode().strip() + "\n"
    return BeautifulSoup(html_doc,"html.parser")
def getTeams():
    t1 = ""
    t2 = ""
    print("Enter team 1")
    input(t1)
    print("Enter team 2")
    input(t2)
    return [t1,t2]

url = r"https://www.espncricinfo.com"
html_doc = getHtml(url+"/records").find_all(class_="ds-relative")[0]
# print(html_doc)
anchors = html_doc.find_all('a')
# print(anchors)
links = []
for i in anchors:
    # print(i)
    # print(i.get("href"))
    links.append(i.get("href"))
for i in links:
    if (i!=None and i[0] == "/" and i.split('/')[1] == "records" and len(i.split('/'))>2):
                link = url+i
                print(link)
    # print("processing1: {}".format(link))
    # page = str(getHtml(link).body.encode("ascii"))
    # print("processing2")
    
    # print(page)
    # break

#     
        



