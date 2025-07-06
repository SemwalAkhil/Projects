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
    path = file_name(r"D:\Projects\Python\Selenium\outputDir\code12")
    with open(path,"w",encoding="utf-8") as file:
        body = driver.find_element(By.ID,"mw-content-text")
        lists = body.find_elements(By.TAG_NAME,"ul")
        for li in lists: 
            list_ele = li.find_elements(By.TAG_NAME,"li")
            for ele in list_ele:
                try:
                    anchor = ele.find_element(By.TAG_NAME,"a")
                    href = anchor.get_attribute("href")
                except:
                    pass
                if href:
                    file.write(anchor.text + "\n")
                    print(href)
    print(f"Written to : {path}")
    driver.quit()

url = "https://en.wikipedia.org/wiki/List_of_restaurant_chains_in_India"
getHtml(url)