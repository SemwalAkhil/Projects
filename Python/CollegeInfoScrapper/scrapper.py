from bs4 import BeautifulSoup
import urllib.request
import csv

def getHtml(url:str):
    fhand = urllib.request.urlopen(url)
    html_doc = ""
    for line in fhand:
        html_doc += line.decode().strip() + "\n"
    return BeautifulSoup(html_doc,"html.parser")

domain = r"https://www.collegedekho.com"
# url = r"/colleges-in-chandigarh_city/"
# url = r"/colleges-in-chandigarh_city/?page=2"
# url = r"/colleges-in-mohali/"
url = r"/colleges-in-panchkula/"
html_doc = getHtml(domain+url)
docs = html_doc.find_all(class_='collegeCardBox')
for i in docs:
    print("----------------------------------------------------------------------")
    anchor = i.find_all('a')[0] 
    name = anchor.get_text().strip()
    collegeWebsite = anchor.get("href")
    # print(name," ",domain+collegeWebsite)
    collegePage = getHtml(domain+collegeWebsite)
    info = collegePage.find_all(class_="contactLocationAddress_collegeAddress__lFOqq")
    email = "Email not found"
    if (len(info) != 0):
        info = info[0]
        email = info.find_all('ul')[0].find_all('li')[1].get_text().strip()
    print(name," ",email)
    try:
        with open(r"D:\Projects\Python\CollegeInfoScrapper\data.csv","a", newline='', encoding='utf-8') as csvFile:
            writer = csv.writer(csvFile,quoting=csv.QUOTE_ALL)
            writer.writerow([name,email])
    except:
        print("Failed to write data!!!")