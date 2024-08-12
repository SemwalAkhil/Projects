class MyClass:
    def __init__(self):
        self.public_var = 10  # Public variable
        self._protected_var = 20  # Protected variable
        self.__private_var = 30  # Private variable

    def public_method(self):
        print("Public method")

    def _protected_method(self):
        print("Protected method")

    def __private_method(self):
        print("Private method")

obj = MyClass()
print(obj.public_var) 
print(obj._protected_var) 
# print(obj.__private_var)  # This will raise an error

obj.public_method()  # Calling public method
obj._protected_method()  # Calling protected method (discouraged)
# obj.__private_method()  # This will raise an error