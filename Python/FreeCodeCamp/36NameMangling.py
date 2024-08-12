class MyClass:
    def __init__(self):
        self.__private_attribute = 42

    def __private_method(self):
        print("This is a private method")
obj = MyClass()
# print(obj.__private_attribute)  # Raises AttributeError

print(obj._MyClass__private_attribute)  # Outputs: 42
obj._MyClass__private_method()  # Outputs: This is a private method


