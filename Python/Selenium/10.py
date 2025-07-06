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

def getHtml(url):
    options = uc.ChromeOptions()
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-blink-features=AutomationControlled")
    driver = uc.Chrome(options=options)
    driver.get(url)
    WebDriverWait(driver,100).until(
        EC.presence_of_element_located((By.ID,"truste-consent-required"))
    )
    driver.find_element(By.ID,"truste-consent-required").click()
    time.sleep(2)
    places = driver.find_element(By.CLASS_NAME,"locationResults").find_elements(By.TAG_NAME,"a")
    links = []
    placeName = []
    for place in places:
        placeLink = place.get_attribute("href")
        if placeLink:
            links.append(placeLink)
            placeName.append(place.text)
    count = 0
    page = 0
    with open("NewResList5.txt","w",encoding="utf-8") as file:
        for l in range(len(links)):
            driver.get(links[l])
            print(f"##########################{placeName[l]}##########################")
            time.sleep(random.randint(0,4))
            while True:
                try:
                    cards =  driver.find_elements(By.TAG_NAME,"a")
                    for i in cards:
                        link = i.get_attribute("href")
                        if link and link.startswith("https://www.dnb.com/business-directory/company-profiles"):
                            # if re.match(r"[\S\s]+page=[0-9]+$",link):
                            #     break
                            file.write(i.text + "\n")
                            count += 1
                            print(f"{count} > {i.text}")
                    navs = driver.find_element(By.CLASS_NAME,"integratedSearchPaginationPagination")
                    if navs:
                        nxt = navs.find_element(By.CLASS_NAME,"next")
                        if nxt:
                            a = nxt.find_element(By.TAG_NAME,"a")
                            if a:
                                href = a.get_attribute("href")
                                if href:
                                    driver.get(href)
                                    page += 1
                                    print(f"<============================={page}=============================>")
                    time.sleep(random.randint(0,4))
                except:
                    break
    driver.quit()

url = "https://www.dnb.com/business-directory/company-information.restaurants_and_other_eating_places.sa.html"
getHtml(url)