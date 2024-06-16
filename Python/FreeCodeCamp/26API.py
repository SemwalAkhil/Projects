import urllib.request,urllib.parse
import json

# Sends request to api to show a random joke with punchline

def showJoke():
    url = r"https://official-joke-api.appspot.com/random_joke"
    uhand = urllib.request.urlopen(url)
    data = uhand.read().decode()
    js = json.loads(data)
    print(js["setup"])
    input("Hit Enter")
    print(js["punchline"])

showJoke()
