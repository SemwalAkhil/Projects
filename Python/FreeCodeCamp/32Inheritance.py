class electronics:
    def __init__(self,name:str="Device",status:int = 0):
        self.name = name
        if (status == 1):
            self.status = "on"
        elif (status == 0):
            self.status = "off"
        else:
            self.status = "unknown"
    def turnOn(self):
        self.status = "on"
        print("{} turned on".format(self.name))
    def turnOff(self):
        self.status = "off"
        print("{} turned off".format(self.name))
class smartPhone(electronics):
    def call(self,name:str):
        print("Calling {}".format(name))

print("------------------------------------------")
device = electronics()
device.turnOn()
device.turnOff()
print("------------------------------------------")
mobile = smartPhone(name="Android")
mobile.turnOn()
mobile.call("someone")
mobile.turnOff()
print("------------------------------------------")
