// 1. Write a C++ program to create an abstract class Animal with an abstract method called sound(). Create derived classes Lion and Tiger that extend the Animal class and implement the sound() method to make a specific sound for each animal.

#include <iostream>
using namespace std;
class Animal{
    public:
        virtual void sound() = 0;
};
class Lion : public Animal{
    public:
    void sound() override{
        cout<<"LION'S ROAR"<<endl;
    }
};
class Tiger : public Animal{
    public:
    void sound() override{
        cout<<"TIGER'S ROAR"<<endl;
    }
};
int main() {
    Animal* ptr1; 
    Lion lion;
    Tiger tiger;
    ptr1 = &lion;
    ptr1->sound();
    ptr1 = &tiger;
    ptr1->sound();
    return 0;
}