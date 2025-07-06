import undetected_chromedriver as uc
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
import re
import random
import os

def file_name(path:str)->str:
    if not os.path.exists(path):
        os.makedirs(path,exist_ok=True)
    count = 0
    while (True):
        if count == 0:
            temp_path = os.path.join(path,"newResList.txt")
            if os.path.exists(temp_path):
                count += 1
                continue
            else:
                return temp_path
        else:
            temp_path = os.path.join(path,f"newResList{count}.txt")
            if os.path.exists(temp_path):
                count += 1
                continue     
            else:
                return temp_path
        

def getHtml(url):
    options = uc.ChromeOptions()
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-blink-features=AutomationControlled")
    driver = uc.Chrome(options=options)
    next_page = True
    driver.get(url)
    path = file_name(r"D:\Projects\Python\Selenium\outputDir\code14")
    with open(path,"w",encoding="utf-8") as file:
        rows = driver.find_elements(By.TAG_NAME,"tr")
        for row in rows: 
            if not row.get_attribute("class"):
                datas = row.find_elements(By.TAG_NAME,"td")
                for i,data in enumerate(datas):
                    if i == 2:
                        try:
                            splits = data.text.rsplit(";")
                            if len(splits) > 1:
                                name = data.text.rsplit(";")[-1]
                                try:
                                    name = name.rsplit("-")[1]
                                    file.write(name + "\n")
                                except:
                                    file.write(name + "\n")
                            else:
                                file.write(data.text + "\n")
                        except:
                            pass
    print(f"Written to : {path}")
    driver.quit()

url = "https://hospitality.economictimes.indiatimes.com/restaurant-nightlife-awards-2023/winners-list#:~:text=Plum%20by%20Bent%20Chair,Emerging%20Brand%20of%20the%20Year"
# print(os.path.join(os.path.curdir,r"code14"))
getHtml(url)