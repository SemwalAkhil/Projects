# /// script
# requires-python = ">=3.10"
# dependencies = [
#     "bs4",
#     "selenium",
# ]
# ///

from scrapper import Scrapper
import os

def writeLog(text:str,file_name:str) -> bool:
    logDir = os.curdir.join

def main():
    scrapper = Scrapper()
    domain = r"https://www.espncricinfo.com/"
    with open(os.path.join("D:\Projects\temp\newProject\logs","log1.txt"),"w",encoding="utf-8") as f:  
        f.write(scrapper.get(domain))

if __name__ == "__main__":
    main()

