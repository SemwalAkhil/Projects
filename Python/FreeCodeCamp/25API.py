import urllib.request, urllib.parse, urllib.error
import json

# This class send name to api which returns age

class AgeGuesser:
    url = r"https://api.agify.io?"
    age = 0
    def __init__(self,name:str,countryCode:str = "IN"):
        self.url += urllib.parse.urlencode({"name":name})
        fhand = urllib.request.urlopen(self.url)
        data = fhand.read().decode()
        # print("Retreived : ",len(data)," characters")
        try:
            js = json.loads(data)
        except:
            js = None
        if (js==None) or ('age' not in js):
            print (' ==== Failure To Retrieve ==== ')
            print (data)
            return
        self.age = js["age"]
    def getAge(self):
        return self.age

if __name__ == "__main__":    
    try:
        name = input("Enter name : ")
    except:
        print("Invalid Name! Exiting code")
        exit()
    ag = AgeGuesser(name)
    print("Guessed age is : ",ag.getAge())
        
    
