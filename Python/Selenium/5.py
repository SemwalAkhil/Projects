# leetcode scrapper
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

domain = r"https://leetcode.com"
url = r"https://leetcode.com/studyplan/top-interview-150/"

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

driver = setup_driver()
driver.get(url)
# # __next
# WebDriverWait(driver,100).until(
#     EC.presence_of_element_located((By.CLASS_NAME,"w-full overflow-hidden rounded-lg border-[1.5px] border-lc-fill-02 dark:border-dark-lc-fill-02"))
# )
time.sleep(5)
soup = BeautifulSoup(driver.page_source,"html.parser")
anchors = soup.find_all("a")
links = []
for anchor in anchors:
    links.append(anchor["href"])
# print(links)
problemLinks = []
# and (str(link).find("/editorial/") != -1)
for link in links:
    if (str(link).startswith("/problems/")) :
        problemLinks.append(re.findall(r"(/problems/[A-Za-z0-9-]+/)",link)[0])
# print(problemLinks)
# print(re.findall(r"(/problems/[A-Za-z0-9-]+/)",'/problems/maximal-square/editorial/?envType=study-plan-v2&envId=top-interview-150'))   
with open("LeetProblems.txt","w", encoding="utf-8") as file:
    for i in problemLinks:
        driver.get(domain+i) 
        WebDriverWait(driver,100).until(
            EC.presence_of_element_located((By.ID,"qd-content"))
        )
        desc = driver.find_element(By.ID,"qd-content").text
        try:
            desc = re.findall(r"Test Result([\s\S]+)Accepted",desc)[0]
        except:
            print(f"Not found {i}")
        file.write(desc)
        file.write("\n-"*5)
        file.write("\n-"*5)
        file.write("\n-\n"*5)
# while True:
#     pass