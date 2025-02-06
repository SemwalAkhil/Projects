# PASS IN THE NUMBER WITH COUNTRY CODE AS COMMAND LINE ARGUEMENT

import phonenumbers
from phonenumbers import geocoder
from phonenumbers import carrier
from opencage.geocoder import OpenCageGeocode
import folium
import sys
from dotenv import load_dotenv
import os

load_dotenv(r"Python\Tracker\.env.local")

KEY = os.getenv("KEY")
print(KEY)
def openDict(dic:dict):
    count = 0
    for i in dic.keys():
        count += 1
        if (type(dic[i]) == dict):
            print(i)
            openDict(dic[i])
        else:
            print(" "*count,i," : ",dic[i])

number = str(sys.argv[1])

pepNumber = phonenumbers.parse(number)
location = geocoder.description_for_number(pepNumber,"en")
print(location)

servicePro = carrier.name_for_number(pepNumber,"en")
print(servicePro)
geocoder = OpenCageGeocode(KEY)
query = str(location)
result = geocoder.geocode(query)
for i in result:
    openDict(i)

lat = result[0]["geometry"]["lat"]
lng = result[0]["geometry"]["lng"]
print(lat,lng)

myMap = folium.Map(location=[lat,lng],zoom_start=9)
folium.Marker([lat,lng],popup=location).add_to(myMap)

myMap.save(r"D:\Projects\Python\Tracker\location.html")