# scrapping https://guide.michelin.com/en/us/restaurants
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
# import re
# import csv
# import os

def setup_driver(adblocker_path:str=""):
    options = Options()
    options.add_argument("--headless")  # Run browser in headless mode
    options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
    options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
    options.add_argument("--log-level=3")  # Reduce logging output
    options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
    options.add_argument("--disable-webgl")  # Disables WebGL rendering
    if adblocker_path != "":
        options.add_extension(adblocker_path)
    return webdriver.Chrome(options=options)

url = r"https://guide.michelin.com/en/us/restaurants"
driver = setup_driver()
driver.get(url)
# WebDriverWait(driver,10).until(
#     EC.presence_of_element_located((By.CLASS_NAME,"didomi-continue-without-agreeing"))
# )
# driver.find_element(By.CLASS_NAME,"didomi-continue-without-agreeing").click()
pageNum = 1
j = 0
with open("resList.txt","w",encoding="utf-8") as file:
    while True:
        # time.sleep(5)
        WebDriverWait(driver,100).until(
            EC.presence_of_element_located((By.CLASS_NAME,"search-results"))
        )
        section = driver.find_element(By.CLASS_NAME,"search-results")
        anchors = section.find_elements(By.TAG_NAME,"a")
        jOld = j
        for k,i in enumerate(anchors):
            try:
                # if str(i.get_attribute("class")).find("info-box") and str(i.get_attribute("class")).find("btn") and str(i.get_attribute("class")).find("link") and str(i.get_attribute("class")).find("image-wrapper") and i.text != "":
                if str(i.get_attribute("class"))  == "" and str(i.text) != "":
                    j += 1
                    file.write(f"{j} > page {pageNum} > {i.text} > {i.get_attribute('class')}\n")
            except:
                print(f"failed at index {k} -> {i}")
        print(pageNum," done ",j - jOld, "on this page")
        if pageNum == 1:
            nextPage = driver.find_element(By.CLASS_NAME,"arrow")
        elif pageNum == 78:
            break
        else:
            nextPage = driver.find_elements(By.CLASS_NAME,"arrow")[1]
        nextPage.click()
        print(driver.current_url)
        WebDriverWait(driver,100).until(
            EC.url_changes(driver.current_url)
        )
        print(driver.current_url)
        time.sleep(5)
        pageNum += 1

driver.close()