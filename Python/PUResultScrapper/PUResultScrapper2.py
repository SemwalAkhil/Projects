# BEAUTIFUL SOUP SCRAPPER II
import requests                 # to send request to browser page
from bs4 import BeautifulSoup   # to scrap the web page and extract data
import csv                      # to save data to a csv file
import re                       # to use regular expressions
from tqdm import trange         # to make a progress bar

'''
    This code is based on given version of the specified site and may need modification based on usage
'''

class resulltScraper:
    def __init__(self,url:str="",headers:dict={},data:dict={}) -> None: 
        '''
            initialisation of class with arguement
                url -> url of the result page
                headers -> used to mimic browser
                data -> commands to mimic user input
            these arguments can be passed during class initialisation or at function call
        '''
        # URL for the form action
        self.url = url 
        # Headers to mimic a browser
        self.headers = headers
        self.data = data

    def browser(self,url:str="",headers:dict={},data:dict={}):
        '''
            browser is used to initiate a post requests imitating a browser
        '''
        if (len(url) == len(headers) == len(data) == 0):
            url = self.url
            headers = self.headers
            data = self.data
        # Send POST request
        response = requests.post(url, headers=headers, data=data)
        return response
    
    def getOne(self,rollNo:int,url:str="",headers:dict={},data:dict={})->list:
        '''
            get result of individual roll no. 
        '''
        if (len(url) == len(headers) == len(data) == 0):
            url = self.url
            headers = self.headers
            data = self.data
        data['ctl00$cph1$txtRollNo'] = str(rollNo)
        response = self.browser(url,headers,data)
        soup = BeautifulSoup(response.content,"html.parser")
        # print(soup)
        data["__VIEWSTATEGENERATOR"]= soup.find(id="__VIEWSTATEGENERATOR")['value'] # type: ignore
        data["__VIEWSTATE"]= soup.find(id="__VIEWSTATE")['value'] # type: ignore
        data["__PREVIOUSPAGE"]= soup.find(id="__PREVIOUSPAGE")['value'] # type: ignore
        data["__EVENTVALIDATION"]= soup.find(id="__EVENTVALIDATION")['value'] # type: ignore
        try:
            name = soup.find(id="ctl00_cph1_lblCName").text
        except:
            print("Name not found in records")
            return []
        try:
            marks = soup.find(id="ctl00_cph1_lblMarks").text
        except:
            print("Marks not found in records")
            return []
        return [rollNo,name,marks]
        

    def getAll(self,start:int,end:int,createCsv:bool=False,url:str="",headers:dict={},data:dict={})->list:
        '''
            get result of students in given range using getOne() function recursively
        '''
        if (len(url) == len(headers) == len(data) == 0):
            url = self.url
            headers = self.headers
            data = self.data
        marksList = [["roll no.","name","marks"]]
        print("Starting data retrieval, this may take time depending on you internet connection and hardware ....")
        for i in trange(start,end+1):
            marksList.append(self.getOne(i,url,headers,data))
        if len(marksList) == 1:
            print("Retrieval Failed")
            return []

        if createCsv:
            try:
                with open("results.csv","w",newline='') as csvFile:
                    writer = csv.writer(csvFile)
                    writer.writerows(marksList)
            except:
                print("Failed to write data!!!")
            print("Results successfully written to results.csv")
        return marksList

def getValue(string:str,default:int):
    val = input("Enter {string} (default value : {default}) : ".format(string=string,default=default))
    if (val.isnumeric()):
        return int(val)
    return default

if __name__ == "__main__":

    url = "https://results.puexam.in/"
    headers={
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
            }
    session = requests.Session()
    rs = session.post(url=url,headers=headers)
    soup = BeautifulSoup(rs.content,"html.parser")
    options = soup.find_all("a",{"class":"MainLink"})


    for i,j in enumerate(options):
        if (((i % 10) == 0) and (i != 0)):
            try:
                choice = int(input("Enter more values ? (-1:Exit / 1: No / Default: Yes): "))
            except:
                choice = 0
            if(choice == 1):
                break
            if(choice == -1):
                exit()
        print(i,"> ",j.text," ",j["href"])
    sem = int(input("Enter Session : "))
    print("You chose : ",options[sem].text)

    # Extract hidden fields
    target = str(options[sem]["id"]).split(sep="_")
    targetStr = ""
    for i in target:
        targetStr += i
    viewstate = soup.find("input", {"name": "__VIEWSTATE"})['value']
    eventvalidation = soup.find("input", {"name": "__EVENTVALIDATION"})['value']

    # print(targetStr)

    # Step 2: Emulate dropdown selection
    payload = {
        "__EVENTTARGET": targetStr,
        "__VIEWSTATE": viewstate,
        "__VIEWSTATEGENERATOR": "7E21AFCE",
        "__PREVIOUSPAGE": "HCZGGW_z4umFRRcJo1C7ARmIvR7Nu-ebwWFiMTDHMPfM1dYk1UB-TlRpcANQCMkbSOM_7n6LP6YbcHNn6Kz8QnXQ3w0CMkde5yFC4xOjzp01",
        "__EVENTVALIDATION": eventvalidation,
        "ctl00$cph1$ddlSession": -1
    }

    # for i in payload.keys():
    #     print(payload[i])

    rs = session.post(url=url,headers=headers,data=payload)
    # soup = BeautifulSoup(rs.content,"html.parser")
    
    for i in rs.headers.keys():
        print(i," : ",rs.headers[i])
    # print(rs.status_code)
    # print(rs.text)
    # print(rs.url)

    # selects = soup.find_all("select")
    # print(selects)
"""
    results = soup.find(id="ctl00_cph1_tblMainResultLinks")
    links = results.find_all("a")
    for i,j in enumerate(links):
        if (((i % 10) == 0) and (i != 0)):
            try:
                choice = int(input("Enter more values ? (1: No / Default: Yes): "))
            except:
                choice = 0
            if(choice == 1):
                break
        print(i,"> ",j.text)
    subject = int(input("Enter Subject : "))
    print("You chose : ",links[subject].text)
    print(links[subject])
"""
    # print(payload)

    # start = getValue("starting roll no.",23051671)
    # end =  getValue("ending roll no.",23051774)
    # sem = getValue("semester",1)
    # url = "https://results.puexam.in/HomePage.aspx?Sess=uoYiWu2CrbE=" # december 2023
    # # url = 'https://results.puexam.in/ShowResultSemester.aspx?CL=OMWrspIZfRw%3d&SS=uoYiWu2CrbE%3d&Sem=0Zd0+cF3s5g%3d' #sem1
    # # url = "https://results.puexam.in/ShowResultSemester.aspx?CL=OMWrspIZfRw=&SS=tXQnFQnpmFw=&Sem=AmdKUuyjej8="
    # # url = "https://results.puexam.in/ShowResultSemester.aspx?CL=l50z97gRZro=&SS=tXQnFQnpmFw=&Sem=mzi02FJa0LU="
    
    # data = {
    #                     '__VIEWSTATE': '/wEPDwULLTExNzM5OTg3NTAPZBYCZg9kFgICAw9kFgICAw9kFgoCAQ8PFgIeBFRleHRlZGQCBA8PFgIfAAUNRGVjZW1iZXIsMjAyM2RkAgYPDxYCHwAFLkJhY2hlbG9yIG9mIENvbXB1dGVyIEFwcGxpY2F0aW9ucyAxc3QgU2VtZXN0ZXJkZAIJDxBkEBULD1NlbGVjdCBTZW1lc3RlcgExATIBMwE0ATUBNgE3ATgBOQIxMBULAi0xATEBMgEzATQBNQE2ATcBOAE5AjEwFCsDC2dnZ2dnZ2dnZ2dnZGQCCw8QDxYGHg1EYXRhVGV4dEZpZWxkBQlDb2xsX05hbWUeDkRhdGFWYWx1ZUZpZWxkBQlDb2xsX0NvZGUeC18hRGF0YUJvdW5kZ2QQFQUNRnVsbCBTdWJqZWN0cxVSZS1hcHBlYXIgQ2FuZGlkYXRlL3MVRGVmaWNpZW50IENhbmRpZGF0ZS9zFUFkZGl0aW9uYWwgIFN1YmplY3QvcxpJbXByb3ZlbWVudCBvZiBQZXJmb3JtYW5jZRUFAi0xAjM0AjM1AjM2AjM3FCsDBWdnZ2dnFgFmZGQRIGBnzJIr7Rb2aCSUrJaD0+2wn32usv99J5hTKH9pAA==',
    #                     '__VIEWSTATEGENERATOR': '1B01934C',
    #                     '__PREVIOUSPAGE': 'LYtW1wnfngRrVGwRGD7olI6q9R22HPwQHf0bzkABoju9C1k72pLd5p429x_g2CtmuPr9g3xorZeiGcm2igUX_d_ibMkmGVkOOBgSlCMIdUMjb1cq-ZHN3FklC67gWfFR0',
    #                     '__EVENTVALIDATION': '/wEdAC8NWYSAVU+lC2DWJpY4/GViPBz3fLu77W1aBG3ZSnmeBSg/hO2whnNoZzRuuFNjTNn6Q/FwakJbb/5ufeSQEtlur8euZAnI4NJlvPcKsCDAG1+KhWo0RMOcxfAnd+4BzisusdiqTDwyU9T26KANCu95m6mrqh8scR8brxZcSaBNUotnMQ9FBwV8UzvdPRPcNl355CM0pVLNRAjfDaLxNeaOK/vXI5HNnw/jyMZWeYtGK1BnJ/SnV5fR7swLfGGpeFUONbgzgLnx8vdm3UD9s57Y4HIPlrOeSQLttF/t8367aQuBcyL3RSufUtKN5gtKmXwZNj/psJPaOXl+SvuoH5s3yS7BO8d514sSR2jbdL7m3CF1M+eVybi/Tx15IRXPOpgvNRaKRRixEMo8ddd+0OuPE8e6LaD38DeTElYEw+/sUyfARzb8Ahc7mdwGJgZ9AjERg/gruSllifG64Mp+e0PP+n5vjpTYUkymimMWe8zV/b3+QNOSGugUbPBcGyTFWAXw2IOuMez4rWA2oNE3iyEhgNe6LLplnyEJhSnxVv8sd7exxeOmX1Q7QLiUOguRweTM0Ez3y2uyxeV3l0Pve+BBgdI8SZ08h6zN/3B+c0M9EsamaRLMDtOOkWce7AnI0yI1HjqoTQPJVM6aMDqXDUdEbe9F54Ct3B9DtPbGOecZ8sZ1pqqoX7tY1yg3D/A58EVAP97ywZVflwPCTMhNGpy1XoSltHsbWnb+CFwEVWNOtkUlqXR8WaPzd9txaaf6JuJnF7rxFLhmCONS2JCWXIl2CT3KNu+Zs0Y1Hkk8ZLRG9OmDd5vQ5z0MXYGdFsBptO8JTUgdWlbe73HCZea36/tkHM6aVjnxudt0S/K9iL4OZv8yUNaq3bfBREay9c11eR5bvJr6l0xr8vcbXm/a00n0X4t6KyHJkbPJ7uTnnEGqpTASOKRjv6kgva4Lv0+WS9WoYUgQ1PHW+epoYGCHBTadosqKzPArwn0NcOkIAC78AUtyyzsdRlcynAUHDg+GwjKtNYKjXapeP/YgCSRarALO',
    #                     'ctl00$cph1$ddlSemester': str(sem),  # Selected semester value
    #                     'ctl00$cph1$ddlCollCode': '-1',  # Selected exam type value
    #                     'ctl00$cph1$txtRollNo': '#',  # Replace with the actual roll number
    #                     'ctl00$cph1$btnShowResult': 'Show Result'
    #                 }
    
    # # '''
    # # initialisation with arguements
    
    # # print(rs.getOne(23051672))
    # results = rs.getAll(start,end,False)
    # # '''
    # '''
    # # initialisation without arguements
    # rs = resulltScraper()
    # print(rs.getOne(23051672,url,headers,data))
    # # results = rs.getAll(start,end,False,url,headers,data)
    # '''
    # for i in results:
    #     print(i)

