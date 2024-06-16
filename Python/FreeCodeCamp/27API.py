import urllib.request,urllib.parse
import json

# displays detail of an ip

class ipDetector:
    def __init__(self,ip:str = "") -> None:
        self.url = r"http://ipwho.is/" + ip
        uhand = urllib.request.urlopen(self.url)
        data =  uhand.read().decode()
        try:
            self.js = json.loads(data)
            if (self.js["success"] != True) :
                print("-----------------------------------------Retrieval failed-----------------------------------------")
                print("Error : ",self.js["message"])
        except:
            self.js = None
            print("-----------------------------------------Retrieval failed-----------------------------------------")
            print(data)
    def get(self,attribute:str):
        if (self.js != None):
            if (attribute in self.js):
                return self.js[attribute]
            else:
                return "NotFound!!!"
    def getAll(self):
        retString = ""
        if (self.js != None):
            for attribute in self.js:
                retString += attribute + " : " + str(self.js[attribute]) + "\n"
        return retString

if __name__ == "__main__":
    try:
        ip = input("Enter IP (hit enter for your current ip): ")
    except:
        print("Invalid Literal!!")
    ipd = ipDetector(ip) # default arguement leads to your current connection
    print(ipd.get("country"))
    print("\n")
    print(ipd.getAll())
