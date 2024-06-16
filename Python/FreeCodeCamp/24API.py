import urllib.request, urllib.parse, urllib.error
import json
# from googlemaps import convert
from googlemaps import client,geocoding

# serviceurl = 'http://maps.googleapis.com/maps/api/geocode/json?'

# while True:
#     address = input ('Enter location: ')
#     if len(address) < 1: 
#         break

#     url = serviceurl + urllib.parse.urlencode({'address': address})

#     print ('Retrieving', url)
#     uh = urllib.request. urlopen (url)
#     data = uh.read () .decode ()
#     print ('Retrieved', len(data), 'characters')

#     try:
#         js = json. loads (data)
#     except :
#         js = None

#     if not js or 'status' not in js or js['status'] != 'OK':
#         print (' ==== Failure To Retrieve ==== ')
#         print (data)
#         continue

#     lat = js["results"] [0] [ "geometry"] [ "location"] ["lat"]
#     lng = js["results"] [0] ["geometry"] [ "location"] [ "lng"]
#     print ('lat', lat, 'lng', lng)
#     location = js['results' ] [0] [ 'formatted_address']
#     print (location)

cli  = client.Client(key="AIzaSyDdyu4Owgh9rk80Mg1j55m2oYEHyBoGw4Y")
print(geocoding.geocode(cli,"Chandigarh"))

    # AIzaSyDdyu4Owgh9rk80Mg1j55m2oYEHyBoGw4Y