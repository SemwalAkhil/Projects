# scrapping https://www.lusha.com/company-search/restaurants/26/united-states/11/page/1/
import undetected_chromedriver as webdriver
# from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.edge.options import Options
from selenium.common.exceptions import NoSuchElementException
from bs4 import BeautifulSoup
import time
# import re
# import csv
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

def setup_driver(adblocker_path:str=""):
    options = Options()
    # options.add_argument("--headless")  # Run browser in headless mode
    options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
    options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
    options.add_argument("--log-level=3")  # Reduce logging output
    options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
    options.add_argument("--disable-webgl")  # Disables WebGL rendering
    if adblocker_path != "":
        options.add_extension(adblocker_path)
    return webdriver.Chrome(options=options)

# url = r"https://www.lusha.com/company-search/restaurants/26/united-states/11/page/1/"
# url = r"https://www.lusha.com/company-search/restaurants/26/united-arab-emirates/13/"
# url = r"https://www.lusha.com/company-search/restaurants/26/kuwait/120/"
# url = r"https://www.lusha.com/company-search/restaurants/26/india/137/"
url = r"https://www.lusha.com/company-search/restaurants/26/india/137/"
driver = setup_driver()
driver.get(url)
# driver.fullscreen_window()
pageNum = 1
j = 0
WebDriverWait(driver,100).until(
            EC.element_to_be_clickable((By.ID,"onetrust-close-btn-container"))
        )

driver.find_element(By.ID,"onetrust-close-btn-container").click()
count = 0
path = r"D:\Projects\Python\Selenium\outputDir\code7"
count = 0
path = file_name(path)
with open(path,"w",encoding="utf-8") as file:
    while True:
        WebDriverWait(driver,100).until(
                EC.presence_of_element_located((By.CLASS_NAME,"directory-content-box-col"))
            )
        section = driver.find_element(By.CLASS_NAME,"directory-content")
        names = section.find_elements(By.CLASS_NAME,"directory-content-box-col")
        for i in names:
            count += 1
            file.write(f"{i.text}\n")
            print(f"\r{count}\r")
        try:
            if (driver.find_element(By.CSS_SELECTOR,"a.next.page-numbers")):
                newLink = driver.find_element(By.CSS_SELECTOR,"a.next.page-numbers").get_attribute("href")
                if newLink:
                    time.sleep(5)
                    driver.get(newLink)
                else:
                    continue
        except NoSuchElementException:
            break
        except Exception as e:
            print("Print and error occured : ",e)
            break

driver.close()