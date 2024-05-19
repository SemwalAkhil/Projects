from random import *
lst=[]
for i in range(10):
	lst.append(randint(0,107))

print(lst)

def arr(lst):
	for j in range(len(lst)):
		for i in range(len(lst)-1):
			if lst[i]>lst[i+1]:
				temp=lst[i+1]
				lst[i+1]=lst[i]
				lst[i]=temp
				print(lst)
	print(lst)
	
def sel(lst):
	for j in range(len(lst)):
		for i in range(len(lst)-1):
			if lst[i]>lst[j]:			
				temp=lst[i]
				lst[i]=lst[j]
				lst[j]=temp
		print(lst)

sel(lst)
			
			