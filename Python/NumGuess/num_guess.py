def rs(lst):
	from random import randint,randrange
	r=randint(0,len(lst)-1)
	for i in range(len(lst)):
		temp=lst[r]
		lst[r]=lst[i]
		lst[i]=temp
	return lst
def numbguess():
	print("GUESS THE X")
	from random import randint,randrange
	point=5
	a=randint(0,1000)
	rand10=a*(randint(1,10))
	sel_lst=[0,1,2,3,4,5,6,7,8,9]
	print("X is greater than "+str(a-(randint(0,100))))
	print("X is less than "+str(a+(randint(0,100))))
	for i in range(a//(randint(1,10))):
		if i!=0:
			if a%i==0:
				print("X is divisble by "+str(i))
	ans=int(input("X is ???"))
	h1=("MULTIPLES OF X "+str(1*rand10)+" "+str(7*rand10)+" "+str(18*rand10)+" "+str(9*rand10)+" "+str(3*rand10))
	h2=("LAST DIGIT OF X IS "+str(a%10))
	ranrage=[]
	for i in range(10):
		ranrage.append(randrange(0,100,5))
	h3=("X IS ANY ONE OF THE FOLLOWING :")
	hint=[h1,h2]
	for i in range(2):
		if ans==a:
				print("RIGHT ANSWER!!!")
				print(str(point)+" POINT")
				break
		else:
			print(hint[i])
			point-=2
			ans=int(input("X is ???"))
				
	else:
		print(h3)
		for j in range(10):
			print(a+((rs(sel_lst))[i])*10)
		ans=int(input("X is ???"))
		if ans==a:
				print("RIGHT ANSWER!!!")
				print(str(point)+" POINT")
		else:
			print("BETTER LUCK NEXT TIME :(")
			print("X IS ",a)
			point=0
	name=input("ENTER NAME : ").upper()
	player=name+" "+str(point)
	try:	
		fin=open("numbguessscores.txt","a")
	except:
		fin=open("numbguessscores.txt","w")
	print(player)
	fin.write(player)
	fin.close()
	
print("WANT TO PLAY ??? (YES/NO)")
usr_in=input(" ")
	
numbguess()
	