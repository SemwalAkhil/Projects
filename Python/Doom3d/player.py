from settings import*
import pygame as pg
import math

class Player:		#fifth call
	def __init__(self,game):
		self.game=game
		self.x,self.y=PLAYER_POS
		self.angle=PLAYER_ANGLE
		
	def movement(self):		#eighth call
		sin_a=math.sin(self.angle)
		cos_a=math.cos(self.angle)
		speed=PLAYER_SPEED*self.game.delta_time
		self.speed_sin=speed*sin_a		
		self.speed_cos=speed*cos_a
		self.dx=self.speed_cos*0.5
		self.dy=self.speed_sin*0.5
		
		
	
	def draw(self):		#eleventh call
		pg.draw.line(self.game.screen,"yellow",(self.x*100,self.y*100),(self.x*100+WIDTH*math.cos(self.angle),self.y*100+WIDTH*math.sin(self.angle)),2)
		pg.draw.circle(self.game.screen,"green",(self.x*100,self.y*100),15)
	
	def update(self):		#seventh call
		self.movement()
		
	@property	#
	def pos(self):
		return self.x,self.y
		
	@property
	def map_pos(self):
		return (self.x),int(self.y)
		
	def check_wall(self,x,y):
		return (x,y) not in self.game.map.world_map
	
	def check_wall_collision(self,dx,dy):
		if self.check_wall(int(self.x+self.dx),int(self.y)):
			self.x+=self.dx
		if self.check_wall(int(self.x),int(self.y+self.dy)):
			self.y+=self.dy