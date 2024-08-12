class myClass:
    funcCallCount = 0
    name = ""
    def __init__(self,name:str):
        print("class created")
        print("calling function")
        self.name = name 
        self.func()
    def func(self):
        print("function called by {name}".format(name=self.name))
        self.funcCallCount += 1
    def __del__(self):
        print("class destroyed")

obj1 = myClass("obj1")
obj1.func()
print(obj1.funcCallCount)

obj2 = myClass("obj2")
obj2.func()
print(obj2.funcCallCount)