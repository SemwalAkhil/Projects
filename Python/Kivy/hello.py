import kivy
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.button import Button
from kivy.uix.gridlayout import GridLayout

class MyGridLayout(GridLayout):
	def __init__(self,**kwargs):
		super(MyGridLayout,self).__init__(**kwargs)
		self.cols=9
		self.text="0"
		for i in range(0,4):
			self.add_widget(Label(text=""))
		self.add_widget(Label(text="SUDOKU SOLVER"))
		for i in range(0,4):
			self.add_widget(Label(text=""))
		self.Box=Button(text=self.text)
		self.add_but()
		
	def add_but(self):
		for i in range(0,81):
			self.Box=Button(text=self.text)
			self.Box.bind(on_press=self.press)
			self.add_widget(self.Box)
		
	def press(self,instance):
		self.text=str(int(self.Box.text)+1)
		self.add_but()
		
class MyApp(App):
	def build(self):
		return MyGridLayout()
	
	
		

if __name__=="__main__":
	MyApp().run()
