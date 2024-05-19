
def draw(per):	
	l=[0,1,2,3,4,5,6,7,8,9,10]
	l[0]=("============")
	l[1]=(" | ")
	l[2]=(" | ")
	l[3]=(" | ")
	l[4]=(" | ")
	l[5]=(" | ")
	l[6]=(" |🥺")
	l[7]=(" \|/")
	l[8]=("  | ")
	l[9]=(" / \ ")
	l[10]=("🔥🔥🔥🔥🔥🔥")
	if per == 100:
		for count in range(1):
			print(l[count])
		print(l[6])
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per <= 100 and per>60:
		for count in range(2):
			print(l[count])
		print(" |🥳")
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per <= 60 and per>40:
		for count in range(3):
			print(l[count])
		print(l[6])
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per <= 40 and per>20:
		for count in range(4):
			print(l[count])
		print(l[6])
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per <= 20 and per>0:
		for count in range(5):
			print(l[count])
		print(l[6])
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per == 0 :
		for count in range(6):
			print(l[count])
		print(l[6])
		print(l[7])
		print(l[8])
		print(l[9])
		print(l[10])
	elif per<0:
		for count in range(8):
			print("	")
		print("\🥺/")
		print(l[10])

    
    

def hangman():
	import csv
	from random import randint
	word_lst=[]
	with open("wordlist.csv","r") as fin:
		data=csv.reader(fin)
		for i in data:
			word_lst.append(i)
	ind=randint(0,len(word_lst[0]))
	word=list(word_lst[0][ind])
	for i in word:
		if i==" ":
			word.remove(i)
	score=0
	per=0
	lst=[]	
	for i in range(len(word)):
		lst.append("[]")
	print("GUESS THE WORD SAVE THE INNOCENT YOU HAVE "+str(len(word)+3)+" TURNS")	
	for i in range(len(word)):
		print("[]")
	print("EMPTY BOXES FILL UP WHEN YOU GUESS A LETTER ")
	i=0	
	while i<(len(word)+3) and word!=lst:		
		i+=1
		user_in=(input("NOW GUESS THE WORD ONE LETTER AT A TIME :"))
		if len(user_in)>1:
			user_in=user_in[0]
		draw(per)		
		for j in range(len(word)):			
			if user_in==word[j]:
				lst[j]=user_in
				score+=1
				per=score/len(word)			
			print(lst[j])
		
	if word==lst:
				print("YOU WON !!!")				
	else:
		print("YOU LET THE INNOCENT DIE!!!")
		per=-1
		draw(per)
	name=input("YOUR NAME ?")
	score=(score/len(word))*100
	usr_id=name+"\t"+str(score)+"\t"+str(word)+"\n"
	print(usr_id)	
	try:
		with open("score_hangman.txt","a") as fin:
			fin.write(usr_id)
	except:
		with open("score_hangman.txt","w") as fin:
			fin.write(usr_id)
while True:
	user_in=input("WANT TO PLAY HANGMAN (YES/NO)").upper()
	if user_in=="YES":
		hangman()	
	else:
		break	

	
		
	