# PM SHRI SCHOOL DATA SCRAPPER
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.options import Options
import time
import re
import csv

options = Options()
options.add_argument("--headless")  # Run browser in headless mode
options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
options.add_argument("--log-level=3")  # Reduce logging output
options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
options.add_argument("--disable-webgl")  # Disables WebGL rendering

driver = webdriver.Chrome(keep_alive=True,options=options)

url = r"https://pmshri.education.gov.in/state"
driver.get(url)
more = WebDriverWait(driver,10).until(
    EC.presence_of_element_located((By.CLASS_NAME,"readMorehome"))
)
#Scroll using ActionChains
actions = ActionChains(driver)
actions.move_to_element(more).perform()
more.click()
state = WebDriverWait(driver,10).until(
    EC.presence_of_element_located((By.ID,"state"))
)
driver.find_element(By.ID,"state")
states = state.find_elements(By.TAG_NAME,"option")
for i,j in enumerate(states):
    print(f"{i} > {j.text}")
stateIndex = int(input("Choose state : "))
state.click()
states[stateIndex].click()
search = driver.find_element(By.CLASS_NAME,"advance-search-button")
search.click()
driver.refresh()

WebDriverWait(driver,10).until(EC.presence_of_element_located((By.CLASS_NAME,"blog-slider")))

data = []
count = 1
while True:
    next = driver.find_element(By.ID,"nextPage")
    slides = driver.find_elements(By.CLASS_NAME,"blog-slider")
    for slide in slides:
        school_details = []
        print(f"School {count}",end="\r")
        name = slide.find_element(By.TAG_NAME,"h2")
        links = slide.find_elements(By.CLASS_NAME,"school-sub-h")
        # print(name.text)
        school_details.append(re.findall(r"^\s*([^,]*),",name.text)[0])
        for link in links:
            try:
                school_details.append(re.findall(r":\s*(.*)",link.text)[0])
            except:
                try:
                    school_details.append(re.findall(r"[a-zA-z0-9]+@[a-zA-z0-9]+\.com",link.text)[0])
                except:
                    school_details.append("")
        data.append(school_details)
        count += 1
        # break
    # break
    if next.is_enabled():
        actions.move_to_element(next).perform()
        next.click()
        time.sleep(2)
    else:
        break
    # break
driver.quit()
# for i in data:
#     for j in i:
#         print(j)
print(f"Scan complete {count} schools found. Writing to csv")
with open("pmshriData.csv","a") as file:
    writer = csv.writer(file,lineterminator="\n")
    writer.writerow(["Name","School Category","School Management","Email","School Type","School Status","Class","State","District","Block"])
    writer.writerows(data)
print("Writing completed")