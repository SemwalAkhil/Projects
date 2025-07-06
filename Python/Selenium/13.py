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
    path = file_name(r"D:\Projects\Python\Selenium\outputDir\code13")
    with open(path,"w",encoding="utf-8") as file:
        lists = driver.find_elements(By.TAG_NAME,"ul")
        for li in lists: 
            list_ele = li.find_elements(By.TAG_NAME,"li")
            for ele in list_ele:
                try:
                    file.write(ele.find_element(By.TAG_NAME,"h3").text.rsplit("-")[1].split(",")[0] + "\n")
                except:
                    pass
    print(f"Written to : {path}")
    driver.quit()

url = "https://food.ndtv.com/news/ndtv-food-awards-2025-full-list-of-winners-revealed-7984347"
getHtml(url)