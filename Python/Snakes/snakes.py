import pygame
import random
pygame.init()

#game variables 
game=True
white=(255,255,255)
black=(0,0,0)
win=pygame.display.set_mode((1080,2061))
pygame.display.set_caption("SNAKES")
size=pygame.display.get_window_size()
font=pygame.font.SysFont(None,150)
snk_x=size[0]/2
snk_y=size[1]/2
snk_size=30
start=False
fps=30
clock=pygame.time.Clock()
vel_x=10
vel_y=10
f_x=random.randint(100,1000)
f_y=random.randint(100,2000)
col=(255,0,0)
snk_col=(0,0,0)
acc=1
score=0
hiscore=str(0)
temp=0
head=[]
snk_lst=[]
snk_len=2

#functions
def text(txt,col,x,y):
	scr_txt=font.render(txt,True,col)
	win.blit(scr_txt,(x,y))
def plot_snk(win,col,snk_lst,snk_size):
	for head in snk_lst:
		pygame.draw.rect(win,col,[head[0],head[1],snk_size,snk_size])	

#outer loop
while game:
	win.fill(white)
	text("SCORE : "+str(score),black,(size[0]/2)-200,0)
	text("HIGH SCORE : "+hiscore,black,(size[0]/2)-500,100)
	try:
		with open("snk_score.txt","r") as f:
			hiscore=f.read()
	except:
		with open("snk_score.txt","w") as f:
			f.write(str(score))
			hiscore=str(score)	
	touch=pygame.mouse.get_pos()			
	for event in pygame.event.get():
		if event.type==pygame.QUIT:
			game=False
		if event.type==pygame.MOUSEBUTTONDOWN:
			start=True			
			if touch[0]>=snk_x and vel_y!=0:
				vel_x=1*abs(temp)
				temp=vel_y
				vel_y=0
			elif touch[0]<snk_x and vel_y!=0:
				if vel_x!=0:
					vel_x=-1*abs(vel_x)
					temp=vel_y
					vel_y=0
				else:
					vel_x=-1*abs(temp)
					temp=vel_y
					vel_y=0
			elif touch[1]>=snk_y and vel_x!=0:
				vel_y=1*abs(temp)
				temp=vel_x
				vel_x=0
			elif touch[1]<snk_y and vel_x!=0:
				if vel_y!=0:
					vel_y=-1*abs(vel_y)
					temp=vel_x
					vel_x=0
				else:
					vel_y=-1*abs(temp)
					temp=vel_x
					vel_x=0	
					
	#game loop		
	if start==True:
		snk_x+=vel_x		
		snk_y+=vel_y		
		if hiscore=="":
			hiscore=str(0)
		if snk_y<=(0-snk_size) and vel_y<0:
			snk_y=size[1]
		if snk_y>=(size[1]+snk_size) and vel_y>0:
			snk_y=0
		if snk_x<=(0-snk_size) and vel_x<0:
			snk_x=size[0]
		if snk_x>=(size[0]+snk_size) and vel_x>0:
			snk_x=0-(snk_size)
		elif abs(snk_x-f_x)<20 and abs(snk_y-f_y)<20:
				snk_len+=2
				f_x=random.randint(0,size[0]-50)
				f_y=random.randint(0,size[1]-50)
				col_r=random.randint(0,255)
				col_g=random.randint(0,255)
				col_b=random.randint(0,255)
				col=(col_r,col_g,col_b)
				snk_r=random.randint(0,255)
				snk_g=random.randint(0,255)
				snk_b=random.randint(0,255)
				snk_col=(snk_r,snk_g,snk_b)				
				score+=10
				if vel_x!=0:
					vel_x=(vel_x*(abs(vel_x)+acc))/abs(vel_x)
				if vel_y!=0:
					vel_y=(vel_y*(abs(vel_y)+acc))/abs(vel_y)

		head=[snk_x,snk_y]
		snk_lst.append(head)
		if len(snk_lst)>snk_len:
			del snk_lst[0]
		if head in snk_lst[:-1]:
			if score>int(hiscore):
				with open("snk_score.txt","w") as f:
					f.write(str(score))
			start=False
			score=0
			snk_lst=[]
			snk_len=2
			vel_x=10
			vel_y=10	
		plot_snk(win,snk_col,snk_lst,snk_size)
		pygame.draw.rect(win,col,[f_x,f_y,30,30])
		
	if start==False:
		text("TAP TO START",col,170,size[1]/2)	
	clock.tick(fps)
	pygame.display.update()
pygame.quit()
quit()
		