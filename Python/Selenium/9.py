# scrapping https://welcomesaudi.com/restaurant 
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

url = r"https://welcomesaudi.com/restaurant "
# domain = r"https://www.cience.com"
driver = setup_driver()

pageNum = 1
j = 0
count = 0
with open("NewResList4.txt","w",encoding="utf-8") as file:
    while True:
        driver.get(url)
        soup = BeautifulSoup(driver.page_source,"html.parser")
        items = soup.find_all("h5",class_="item-title")
        for i in items:
            j += 1
            print(j,">",str(i.text).strip())
        file.writelines([str(i.text).strip()+"\n" for i in items])
        print(f"<=============================== PAGE {pageNum} ===============================>")
        pageNum += 1
        try:
            next = soup.find("a",attrs={"class":"page-link","aria-label":"Next »"})
            if next:
                url = next.get("href")
        except:
            break
        

driver.close()