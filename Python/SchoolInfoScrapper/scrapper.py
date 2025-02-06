from bs4 import BeautifulSoup
import urllib.request
import requests
import csv
import bs4

def getHtml(url:str):
    # headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    # req = urllib.request.Request(url,headers=headers)
    # with urllib.request.urlopen(req) as fhand:
    #     html_doc = fhand.read().decode('utf-8')
    html_doc = requests.get(url)
    return BeautifulSoup(html_doc.content,"html.parser")
def decrypt_cf_email(encoded_string):
    # Convert hex-encoded string into a byte array
    email_hex = bytes.fromhex(encoded_string)

    # The first byte is the XOR key
    key = email_hex[0]

    # Decrypt remaining bytes
    decrypted_email = ''.join([chr(byte ^ key) for byte in email_hex[1:]])

    return decrypted_email

domain = r"https://www.edustoke.com"
# url = r"/schools-in-Chandigarh/"
# url = r"/schools-in-Mohali/"
url = r"/schools-in-Panchkula/"
# url = r"/schools-in-chandigarh_city/?page=2"
# url = r"/schools-in-mohali/"
# url = r"/schools-in-panchkula/"
# print(domain+url)
html_doc = getHtml(domain+url)
docs = html_doc.find_all(class_='school-card-container')
for i in docs:
    print("----------------------------------------------------------------------")
    anchor = i.find_all('a')[1] 
    name = anchor.get_text().strip()
    schoolWebsite = anchor.get("href")
    # print(name," ",schoolWebsite)
    schoolPage = getHtml(schoolWebsite)
    info = schoolPage.find(id="contact-information").find("span").find("span")
    if (info != None):
        info = info["data-cfemail"]
        email= decrypt_cf_email(info)
        print(name,email)
        try:
            with open(r"D:\Projects\Python\SchoolInfoScrapper\data.csv","a", newline='', encoding='utf-8') as csvFile:
                writer = csv.writer(csvFile,quoting=csv.QUOTE_ALL)
                writer.writerow([name,email])
        except:
            print("Failed to write data!!!")
        # break