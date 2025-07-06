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
    path = file_name(r"D:\Projects\Python\Selenium\outputDir\code11")
    with open(path,"w",encoding="utf-8") as file:
        while next_page:
            time.sleep(random.randint(1,5))
            WebDriverWait(driver,100).until(
                EC.presence_of_element_located((By.TAG_NAME,"p"))
            )

            soup = BeautifulSoup(driver.page_source,"html.parser")
            names = [i.text + "\n" for i in soup.find_all("p",{"data-testid":"vendor-name"})]
            anchors = driver.find_elements(By.TAG_NAME,"a")
            file.writelines(names)
            # print(names)
            for i in anchors:
                if i.get_attribute("aria-current") == "Page":
                    print(i.text)
                if i.get_attribute("aria-label") == "Go to next page" and i.get_attribute("aria-disabled") != "true":
                    while True:
                        try:
                            i.click()
                            break
                        except:
                            pass
                    break
            else:
                next_page = False

    driver.quit()

# url = "https://www.talabat.com/uae/restaurants"
url = "https://www.talabat.com/kuwait/restaurants"
getHtml(url)