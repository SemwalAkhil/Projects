# PKL SCRAPPER
from selenium import webdriver
from selenium.webdriver.common.by import By
from bs4 import BeautifulSoup as bs
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
import csv
import re
import time
import json

policyBtnAccepted = False

def getSeasonsList(driver):
    # time.sleep(2)
    seasons = driver.find_elements(By.CLASS_NAME,"list-item")
    soup = bs(driver.page_source,"html.parser")
    s = soup.find_all(class_="list-item")

    remList = []
    for i in range(len(s)):
        if not (re.search(r"^Season [0-9]+",s[i].text.strip())):
           remList.append(i)
    remList.sort(reverse=True)
    for i in remList:
        seasons.pop(i)
    return seasons

def getFixturePage(driver):
    # time.sleep(2)
    global policyBtnAccepted
    driver.get(r"https://www.prokabaddi.com/schedule-fixtures-results")
    season = driver.find_element(By.CLASS_NAME,"selected-title")
    season = season.find_element(By.CLASS_NAME,"title")
    WebDriverWait(driver,100).until(
        EC.presence_of_element_located((By.CLASS_NAME,"list-item"))
    )
    if not policyBtnAccepted:
        try:
            policyBtn = WebDriverWait(driver,100).until(
                EC.presence_of_element_located((By.ID,"onetrust-reject-all-handler"))
            )
            time.sleep(2)
            policyBtn.click()
            policyBtnAccepted = True
        except:
            pass
    return season

def getTeamInfo(soup,teamC:str):
    # time.sleep(2)
    try:
        team = soup.find_all(class_=f"team team-{teamC}")[0]
        teamData = team.find_all("p")
        for i in range(len(teamData)):
            teamData[i] = teamData[i].text.strip() 
        teamPlayers = soup.find_all(class_=f"scorecard-list scorecard-list-{teamC}")
        playerList = []
        for players in teamPlayers:
            playerList += players.find_all(class_="scorecard-item") 
    except:
        print("Data not found skipping the match")
        return None,None
    for i in range(len(playerList)):
        playerInfo = {}
        try:
            playerName = playerList[i].find_all(class_="player-detail")[0].find_all(class_="left-section")[0].find_all(class_="content")[0].find("a")["title"]
        except:
            print("Error in fetching player data moving to next player")
            continue
        try:
            playerPointsItem = playerList[i].find_all(class_="points-item")
        except:
            print(f"Error in fetching {playerName}'s data moving to next player")
            continue
        playerPointsInfo = {}
        try:
            for j in playerPointsItem:
                playerPointsInfo[j.find(class_="points-label").text.strip()] = j.find(class_="points-value").text.strip()
            playerInfo[playerName.strip()] = playerPointsInfo
        except:
            print(f"Error in fetching {playerName}'s points moving to next player")
            continue
        playerList[i] = playerInfo
    return teamData, playerList

options = Options()
options.add_argument("--headless")  # Run browser in headless mode
options.add_argument("--disable-gpu")  # Disable GPU usage (optional, for compatibility)
options.add_argument("--no-sandbox")  # Disable sandbox (useful in some environments)
options.add_argument("--log-level=3")  # Reduce logging output
options.add_argument("--disable-software-rasterizer")  # Prevents software rendering
options.add_argument("--disable-webgl")  # Disables WebGL rendering

driver = webdriver.Chrome(keep_alive=True,options=options)


season = getFixturePage(driver)
seasons = getSeasonsList(driver)
seasons.reverse()

# exit(1)
# option = driver.find_element(By.ID,"tab3")
# option.click()
history = []
seasonData = {}
teamData = []
for curr in range(len(seasons),0,-1):
    # time.sleep(2)
    print("season: ",curr)
    season.click()
    seasons[curr-1].click()
    option = driver.find_element(By.ID,"tab3")
    option.click()
    # time.sleep(3)
    soup = bs(driver.page_source,"html.parser")
    fixtures = soup.find_all(class_="fixtures-group")
    seasonData[curr] = {}
    for count,i in enumerate(fixtures):
        matchNum = len(fixtures)-count
        # print(f"match: {matchNum}")
        link = i.find_all("a")[0]
        if link['href'] != None:
            # time.sleep(2)
            driver.get("https://www.prokabaddi.com" + link['href'])
            soup = bs(driver.page_source,"html.parser")
            teamAData, playerAList = getTeamInfo(soup,"a")
            teamBData, playerBList = getTeamInfo(soup,"b")
            if (teamAData != None and playerAList != None and teamBData != None and playerBList != None):
                teamData = teamAData + [playerAList,] + teamBData + [playerBList,]
            else:
                print(f"skipping match: {matchNum}")
                continue
            seasonData[curr][matchNum] = teamData
    history.append(seasonData)
    season = getFixturePage(driver)
    seasons = getSeasonsList(driver)
    seasons.reverse()
    break
            # print(teamData)
        # while True:
        #     pass
        # dct[i] = []
        # for j in i.find_all("p"):
        #     dct[i].append(str(j.text).strip())
    # option.click()

# print(history)
with open('pklDataLite.json', 'a') as file:
    json.dump(history, file, indent=4)
# with open("pklData.csv","a") as file:
#     writer = csv.writer(file,escapechar="\n")
#     for key in dct: 
#         writer.writerow(dct[key])
# for key in dct: 
    # print(dct[key])

driver.quit()