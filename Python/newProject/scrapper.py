import requests
from bs4 import BeautifulSoup
import csv
import re
# req = requests.get("https://www.geeksforgeeks.org/")

# soup = BeautifulSoup(req.content,"html.parser")
# res = soup.title.getText()
# # print(soup.prettify())
# # print(soup.getText())
# print(res)

req = requests.get("https://www.espncricinfo.com/series/indian-premier-league-2024-1410320/kolkata-knight-riders-vs-punjab-kings-42nd-match-1426280/full-scorecard")

soup = BeautifulSoup(req.content,"html.parser")
res = soup.table
headers = res.find_all("th")
titles = []
# print(soup.prettify())
# print(soup.getText())
# print(res.find_all("th"))

for i in headers:
    titles.append(i.getText())

data = res.find_all("tr")
# print(data)
dataRow = []
for i in data:
    temp = []
    for j in i:
        text = j.getText()
        # text = text.encode("utf-8", errors="ignore").decode("utf-8")
        text = re.sub(r'[^\x00-\x7F]+', '', text)
        if (text != ""):
            temp.append(text)
    if (len(temp) > 0):
        dataRow.append(temp)
# print(titles)
# for i in dataRow:
#     print(i)



# Open the CSV file in write mode
import csv

# Open the CSV file in write mode
with open(r'D:\Codes\Python\newProject\data.csv', 'w', newline='') as csvfile:
    # Create a csv.writer object
    csvwriter = csv.writer(csvfile)

    # Write data rows
    csvwriter.writerows(dataRow)

print(dataRow)
