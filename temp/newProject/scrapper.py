from bs4 import BeautifulSoup
from selenium.webdriver import Chrome
from selenium.webdriver import ChromeOptions
from selenium import webdriver

class Scrapper:
    def __init__(self) -> None:
        options = webdriver.ChromeOptions()
        self.driver = webdriver.Chrome(options=options)
    
    def get(self,url:str) -> str:
        self.driver.get(url)
        return self.driver.page_source
    
    def __del__(self) -> None:
        self.driver.close()
