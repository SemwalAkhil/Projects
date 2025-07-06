from bs4 import BeautifulSoup
import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
import re
import csv
import time


url = r"https://www.iplt20.com/matches/results"
count = 1

def setup_driver(adblocker_path):
    options = Options()
    options.add_argument("--headless")  # Run browser in headless mode
    options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
    options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
    options.add_argument("--log-level=3")  # Reduce logging output
    options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
    options.add_argument("--disable-webgl")  # Disables WebGL rendering
    options.add_extension(adblocker_path)
    return webdriver.Chrome(options=options)

driver = setup_driver(r"D:\Projects\Python\Selenium\ublock.crx")
driver.get(url)
count = 1
maxCount = 100
WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.CLASS_NAME,"cookie"))
        )
cookie = driver.find_element(by=By.CLASS_NAME,value="cookie")
button = cookie.find_element(by=By.TAG_NAME,value="button")
button.click()
while count < maxCount:
    try:
        WebDriverWait(driver, 100).until(
                EC.presence_of_element_located((By.CLASS_NAME,"ng-scope"))
            )
        body = driver.find_element(By.CLASS_NAME,"ng-scope")
        print("body")
    except:
        print("body not found")
    try:
        main = body.find_elements(By.TAG_NAME,"div")
    except:
        print("main not found")
    for i,j in enumerate(main):
        if (j.get_attribute("class") == "cSBDisplay ng-binding" and j.text.strip().startswith("SEASON")):
            dropDown = j
            break
    j.click()
    listItems = []
    for i in main: 
        if (i.get_attribute("class") == "cSBListItems ng-binding ng-scope" and i.text.strip().startswith("SEASON")):
            listItems.append(i)
    maxCount = len(listItems)
    if len(listItems) > count:
        listItems[count].click()
    else:
        print("Element not found")
    time.sleep(5)
    soup = BeautifulSoup(driver.page_source,"html.parser")
    matchList = soup.find(id="team_archive")
    matchList = matchList.find_all("li")
    delimitedList = []
    for i in matchList:
        delimitedList.append(re.sub(r"\s(\s+)",", ",i.text)[2:-2])
    print(len(delimitedList))
    with open("iplRecs.csv","a",newline="") as file:
        writer = csv.writer(file)
        for i in delimitedList:
            writer.writerow(i.split(","))
    count += 1
exit()
driver.close()