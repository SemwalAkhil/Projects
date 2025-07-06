# wiki scrapper

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
import re
import csv
import os

url = r"https://en.wikipedia.org/wiki/List_of_restaurant_chains_in_the_United_States#:~:text=TGI%20Fridays%20%20%20,17%20%20Southern%20California"
driver = webdriver.Chrome()
driver.get(url)
time.sleep(5)
# print(driver.page_source)
soup = BeautifulSoup(driver.page_source,"html.parser")
tables = soup.find_all("table")
rows = []
for i in tables:
    # if (i.get('class') == "nowraplinks mw-collapsible autocollapse navbox-inner mw-made-collapsible"):
    #     continue
    rows += i.find_all("tr")
names = []
for i in rows:
    try:
        names.append(i.find_all("td")[0].text)
    except:
        pass
for i in names:
    print(i)
with open("nameList.txt","w",encoding="utf-8") as file:
    for i in names:
        file.writelines(i)
driver.close()