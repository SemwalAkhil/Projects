# scrapping https://www.cience.com/companies-database/united-states/restaurants/revenue-100m-250m?page=1 
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.edge.options import Options
from bs4 import BeautifulSoup
import time
# import re
# import csv
# import os

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
    return webdriver.Edge(options=options)

url = r"https://www.cience.com/companies-database/united-states/restaurants/revenue-100m-250m?page=1"
domain = r"https://www.cience.com"
driver = setup_driver()
driver.get(url)
# driver.fullscreen_window()
pageNum = 1
j = 0
# WebDriverWait(driver,100).until(
#             EC.element_to_be_clickable((By.ID,"onetrust-close-btn-container"))
#         )

# driver.find_element(By.ID,"onetrust-close-btn-container").click()
count = 0
with open("NewResList2.txt","w",encoding="utf-8") as file:
    while True:
        WebDriverWait(driver,100).until(
                EC.presence_of_element_located((By.CSS_SELECTOR,".grid.grid-cols-5.gap-4.items-center.bg-white.lg\\:p-4.p-2.rounded-\\[10px\\].mb-2\\.5"))
            )
        rows = driver.find_elements(By.CSS_SELECTOR,".grid.grid-cols-5.gap-4.items-center.bg-white.lg\\:p-4.p-2.rounded-\\[10px\\].mb-2\\.5")
        print(len(rows))
        for i in rows:
            # print(i.find_elements(By.TAG_NAME,"p")[0].text)
            count += 1
            # print(f"{count}. {i.find_elements(By.TAG_NAME,'p')[0].text}\n")
            file.write(f"{count}. {i.find_elements(By.TAG_NAME,'p')[0].text}\n")
            print(f"\r{count}")
        try:
            newLink = driver.find_element(By.CSS_SELECTOR,".page.next").find_element(By.TAG_NAME,"a").get_attribute("href")
            if newLink:
                time.sleep(5)
                # print(newLink)
                driver.get(newLink)
            else:
                continue
        except:
            break

driver.close()