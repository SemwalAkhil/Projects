from bs4 import BeautifulSoup
import urllib.request
import csv

def getHtml(url:str):
    fhand = urllib.request.urlopen(url)
    html_doc = ""
    for line in fhand:
        html_doc += line.decode().strip() + "\n"
    return BeautifulSoup(html_doc,"html.parser")

url = r"https://www.espncricinfo.com"
html_doc = getHtml(url+"/records").find_all(class_="ds-relative")[0]
# print(html_doc)
anchors = html_doc.find_all('a')
# print(anchors)
links = []
linkList = []
for i in anchors:
    print("Fetching pages ....")
    links.append(i.get("href"))

for i in links:
    print("Looking for desired links ...")
    if (i!=None and i[0] == "/" and i.split('/')[1] == "records" and len(i.split('/'))>2):
        link = url+i
        # print(link)
        linkList.append(link)

links = []
for i in linkList:
    print("Looking for match results ...")
    # print(i)
    html_doc = getHtml(i)
    anchors = html_doc.find_all('a')
    for j in anchors:
        relLink = j.get("href")
        # print(relLink)
        if (relLink!=None):
            if (relLink[0] == "/"):
                if (len(relLink.split('/')) >= 4):
                    if (relLink.split('/')[3] == "team-match-results"):
                        link = url+relLink
                        # print(link)
                        links.append(link)

linkList = []
for i in links:
    print("Fetching records ....")
    html_doc = getHtml(i)
    tableRows = html_doc.find_all('tr')
    for row in tableRows:
        datas = row.find_all('td')
        rowList = []
        for data in datas: 
            rowList.append(data.get_text())
        try:
            with open(r"D:\Projects\Python\newProject\data.csv","a",newline='') as csvFile:
                writer = csv.writer(csvFile)
                writer.writerow(rowList)
        except:
            print("Failed to write data!!!")
else:
    print("Results successfully written to data.csv")