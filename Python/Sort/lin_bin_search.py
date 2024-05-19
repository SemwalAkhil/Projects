from random import *
from math import *


#while True:						#take value from user
#	
#	start=(input("Add element (Y/N) : ")).upper()
#	
#	if start=="Y":
#		try:
#			lst.append(int(input("Enter Numbers :")))
#		except:
#			print("ENTER VALID VALUE !")
#	
#	elif start=="N":
#		break

#	else:
#		print("ENTER VALID VALUE !")
#	
#print(lst)	

lst=[]
for i in range(100000):
	lst.append(randint(0,10789700))

lst.sort()

print(lst)

try:
	val=int(input("Value to be searched : "))
except:
	print("ENTER VALID VALUE !")

#LINEAR SEARCH

#for i in range(len(lst)):
#	print(str(lst[i]) + " evaluated ...")
#	if lst[i]==val:
#		print(str(val) + " at "+str(i))
#		break
#else:
#	print("VALUE NOT FOUND !")

#-------------------------------------------------------------------

#BINARY SEARCH

#ul=len(lst)
#ll=0
#	
#while ll<ul:
#	mid=(ul+ll)//2
#	print("value b/w "+ str(ll) + "and "+str(ul))	
#	print(mid)

#	if val==lst[mid]:
#			print('check 3')
#			print(str(val) + " at index " + str(mid))
#			break
#			
#	else:
#		
#		if val>lst[mid]:
#			print('check 1')
#			ll=mid+1
#			print(" new ll is : ",ll)
#		
#		elif val<lst[mid]:
#			print('check 2')
#			ul=mid-1
#			print(" new ul is : ",ul)
#			
#else:		
#	print("VALUE NOT FOUND !")

		
#
