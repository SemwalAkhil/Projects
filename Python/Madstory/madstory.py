def madlib():

	print("MADLIB GENERATOR")
	a=(input("ENTER YOUR NAME :")).upper()
	b=(input("ENTER A FOOD : ")).upper()
	c=(input("SOMETHING YOU WANT :")).upper()
	d=(input("NAME OF A DAY :")).upper()
	e=(input("NAME OF A FRIEND :")).upper()
	f=(input("SOMEONE POWERFUL :")).upper()
	g=(input("YOUR FAVOURITE BIKE/CAR COMPANY :")).upper()
	h=(input("NAME OF VEGETABLE :")).upper()
	i=(input("NAME OF A FRUIT :")).upper()
	j=(input("SOMETHING TO CARRY THINGS  :")).upper()

	try:
		fin=open("madstory.txt","a")
	except:
		fin=open("madstory.txt","w")

	str1="\n"+str(a)+" likes "+str(b)+" , "+str(c)+" on "+str(d)+" morning \n "
	str2=str(e)+" ki "+str(f)+" se request demand "+str(g)+" scooter ki \n "
	str3="Purple "+str(h)+" red "+str(i)+" in "+str(j)+" \n "


	lst=[str1,str2,str3]
	for i in range(len(lst)):
		print(lst[i])

	fin.writelines(lst)

madlib()