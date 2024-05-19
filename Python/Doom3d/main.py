import pygame as pg
import sys
from settings import *
from map import *
from player import *
from raycasting import *


class Game:
	
	def __init__(self):		#first call
		pg.init()		
		self.font=pg.font.SysFont(None,50)
		self.screen=pg.display.set_mode(RES)
		self.clock=pg.time.Clock()
		self.delta_time=1 #
		self.new_game()
		
	def text(self,txt,col,x,y):
		scr_txt=self.font.render(txt,True,col)
		self.screen.blit(scr_txt,(x,y))		
			
	def new_game(self):		#second call
		self.map=Map(self)
		self.player=Player(self)
		self.raycasting=RayCasting(self)
	
	def update(self):		#sixth call
		self.player.update()
		self.raycasting.update()
		pg.display.flip()#		
		self.delta_time=self.clock.tick(FPS)
		pg.display.set_caption(f'{self.clock.get_fps() :.1f}')
			
	def draw(self):		#nineth call
		self.screen.fill('black')#?
		self.map.draw()		
		self.player.draw()
	
	def check_events(self):
		self.touch=pg.mouse.get_pos()
		self.player.check_wall_collision(self.player.speed_cos*0.5,self.player.speed_sin*0.5)
		for event in pg.event.get():
			if event.type==pg.QUIT or (event.type==pg.KEYDOWN and event.key==pg.K_RETURN):
				pg.quit()
				sys.exit()#
			if event.type==pg.MOUSEBUTTONDOWN:
				if self.touch[0]<1030.5:
					self.player.angle-=PLAYER_ROT_SPEED*self.delta_time
				if self.touch[0]>1030.5:
					self.player.angle+=PLAYER_ROT_SPEED*self.delta_time
					
			
	def run(self):
		while True:	
			self.update()	
			self.check_events()									
			self.draw()
			self.text("TOUCH POS: "+str((self.touch)),(255,255,255),0,0)
			self.text("FPS: "+str(self.delta_time),(255,255,255),0,100)
			
			
if __name__=="__main__":
	game=Game()
	game.run()