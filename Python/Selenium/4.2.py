# ESPN CRIC SCRAPPER II
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

class Scrapper:

    def __init__(self,domain:str):
        """
        domain : domain to work on
        Initialises the scrapper
        """
        self.domain = domain

    def setupDriver(self,headless:bool=True,disableGpu:bool=True,noSandbox:bool=True,logLevel:int=3,disableSoftwareRaster:bool=True,disableWebGl:bool=True,adblocker_path:str="")->bool:
        """
        headless : Run browser in headless mode
        disableGpu : Disable GPU usage (optional, for compatibility)
        noSandbox : Disable sandbox (useful in some environments)
        logLevel : 0 = ALL, 1 = DEBUG, 2 = INFO, 3 = WARNING, 4 = ERROR, 5 = FATAL
        disableSoftwareRaster : Prevents software rendering
        disableWebGl : Disables WebGL rendering
        adblocker_path : path to adblocker
        Returns true if driver successfully setup
        """
        try:
            options = Options()
            if (headless):
                options.add_argument("--headless")
            if (disableGpu):
                options.add_argument("--disable-gpu")
            if (noSandbox):
                options.add_argument("--no-sandbox")
            options.add_argument(f"--log-level={logLevel}")
            if (disableSoftwareRaster):
                options.add_argument("--disable-software-rasterizer")
            if (disableWebGl):
                options.add_argument("--disable-webgl")
            if (adblocker_path != ""):
                options.add_extension(adblocker_path)
            self.driver = webdriver.Chrome(options=options)
            return True
        except:
            return False
    
    def soup(self,url:str=""):
        """
        url : url of soup to get or domain if none given
        Returns beautifulsoup object for the url
        """
        if url == "":
            self.driver.get(domain)
        else:
            self.driver.get(url)
        WebDriverWait(self.driver, 100).until(
            EC.presence_of_element_located((By.TAG_NAME,"body"))
        )
        return BeautifulSoup(self.driver.page_source,"html.parser")
    
    def urlAppend(self,url:str)->str:
        """
        url : url to append to domain
        Returns appended string
        """
        return self.domain + url
    
    def getLinks(self,url="")->list[str]:
        """
        url : url to check if none given then uses domain
        Returns a list of all the hrefs in the anchor elements
        """
        Soup = self.soup(url)
        links = Soup.find_all("a")
        for i in range(len(links)):
            try:
                links[i] = links[i]["href"]
            except:
                links[i] = None
        return links
    
    def getSpecialLinks(self,pattern:str,links:list[str]=[],url:str=""):
        """
        pattern : pattern to match
        links : (if url not given) list of links
        url : url to pick links from
        Returns a list of all the links that match the pattern
        """
        if (url == ""):
            return list(filter(lambda x: x.find(pattern) != -1 ,links))
        else:
            return list(filter(lambda x: x.find(pattern) != -1 ,self.getLinks(url)))

    
    
domain = r"https://www.espncricinfo.com"
adblocker = r"D:\Projects\Python\Selenium\ublock.crx"
scrapper = Scrapper(domain)
scrapper.setupDriver(headless=False,adblocker_path=adblocker)
print(scrapper.getSpecialLinks(pattern=r"india",url=domain))