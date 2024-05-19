// 1. Write a C++ program to create a class called Animal with a method called makeSound(). Create a derived class called Cat that overrides the makeSound() method to bark.
#include <iostream>
using namespace std;
class Animal{
    public:
    virtual void makeSound(){
        cout<<"ANIMAL MAKING SOUND"<<endl;
    }
};
class Cat : public Animal{
    public:
    void makeSound() override{
        cout<<"CAT MEWS"<<endl;
    }
};
int main() {
    Animal animal;
    Cat cat;
    animal.makeSound();
    cat.makeSound();
    return 0;
}