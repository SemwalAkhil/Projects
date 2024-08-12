import urllib.request, urllib.parse, urllib.error
import json

with open(r"D:\Projects\Python\FreeCodeCamp\29twitter_keys.json","r") as inFile:
    creds = inFile.read()
creds = json.loads(creds)
ACCESS_KEY = creds["ACCESS_KEY"]

def getRandomImage(query:str=""):
    url = "https://api.unsplash.com/"
    url += "photos/random/?client_id={}&query={}".format(ACCESS_KEY,query)
    fhand = urllib.request.urlopen(url)
    data = fhand.read().decode()
    # print("Retreived : ",len(data)," characters")
    try:
        js = json.loads(data)
    except:
        js = None

    if (js==None):
        print (' ==== Failure To Retrieve ==== ')
        print (js)
        return None
    # for key in js:
    #     print(key," : ",js[key])
    return js['urls']['thumb']

if __name__ == "__main__":
    print(getRandomImage())