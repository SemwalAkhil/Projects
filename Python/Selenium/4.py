# ESPN CRIC SCRAPPER
# %%
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

def getLinks(page_source:str,regx:str):
    soup = BeautifulSoup(page_source,"html.parser")
    links = soup.find_all("a")
    for i in range(len(links)):
        try:
            links[i] = links[i]["href"]
        except:
            links[i] = None
    linksTemp = []
    for i in links:
        if (i) and (re.search(regx,i)):
            linksTemp.append(i)
    return linksTemp

url = r"https://www.espncricinfo.com"
driver = setup_driver(r"D:\Projects\Python\Selenium\ublock.crx")
driver.get(url)
soup = BeautifulSoup(driver.page_source,"html.parser")
WebDriverWait(driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME, "a"))
        )
link = soup.find_all("a",title="Cricket Stats")[0]["href"]
try:
    driver.get(link)
except:
    print("Failed")
    exit()
file = open("crickeData.csv","w",newline="")
writer = csv.writer(file)
decLinks = getLinks(driver.page_source,r"^/records/decade")
# print(links)
for decLink in range(len(decLinks)):
    print(decLinks[decLink])
    driver.get(url+decLinks[decLink])
    typeLinks = getLinks(driver.page_source,r"^/records/decade/team-match-results-year")
    for typeLink in range(len(typeLinks)):
        driver.get(url+typeLinks[typeLink])
        yrLinks = getLinks(driver.page_source,r"^/records/year/team-match-results")
        for yrLink in range(len(yrLinks)):
            print(yrLinks[yrLink])
            driver.get(url+yrLinks[yrLink])
            soup = BeautifulSoup(driver.page_source,"html.parser")
            entries = soup.find_all("tr")
            entriesCleared = []
# %%    
            for entry in range(len(entries)):
                try:
                    if (entry):
                        entries[entry] = entries[entry].contents
                        for cols in range(len(entries[entry])):
                            entries[entry][cols] = entries[entry][cols].text
                        entriesCleared.append(entries[entry])
                except:
                    pass
            writer.writerows(entriesCleared)
# %%
file.close()
driver.close()
