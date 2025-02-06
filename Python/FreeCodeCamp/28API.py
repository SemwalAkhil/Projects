import tweepy
import json
import urllib.request,urllib.parse

with open(r"D:\Projects\credentials\29twitter_keys.json","r") as inFile:
    creds = inFile.read()
creds = json.loads(creds)
BEARER_TOKEN = creds["BEARER_TOKEN"]
API_KEY = creds["API_KEY"]
API_KEY_SEC = creds["API_KEY_SEC"]
ACCESS_TOKEN = creds["ACCESS_TOKEN"]
ACCESS_SEC = creds["ACCESS_SEC"]
ACCESS_KEY = creds["ACCESS_KEY"]

# Sends request to api to show a random joke with punchline

def showJoke():
    url = r"https://official-joke-api.appspot.com/random_joke"
    uhand = urllib.request.urlopen(url)
    data = uhand.read().decode()
    js = json.loads(data)
    return [js["setup"] , js["punchline"]]

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

client = tweepy.Client(bearer_token=BEARER_TOKEN,consumer_key=API_KEY,consumer_secret=API_KEY_SEC,access_token=ACCESS_TOKEN,access_token_secret=ACCESS_SEC)
"""
query = client.get_me()
print(query)
"""
"""
query = client.delete_tweet(id="1803794838833295865")
print(query)
"""
joke = showJoke()
text = joke[0] + "\n\n" + joke[1]
query = client.create_tweet(text=text)
print(query)