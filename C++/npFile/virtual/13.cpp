// 13. Write a C++ program to create an abstract class Bird with abstract methods fly() and makeSound(). Create derived classes Eagle and Hawk that extend the Bird class and implement the respective methods to describe how each bird flies and makes a sound.
#include <iostream>
using namespace std;
class Bird{
    public:
        virtual void makeSound() = 0;
        virtual void fly() = 0;
};
class Eagle : public Bird{
    public:
    void makeSound() override{
        cout<<"EAGLE'S SCREECH"<<endl;
    }
    void fly() override{
        cout<<"EAGLE SOARS"<<endl;
    }
};
class Hawk : public Bird{
    public:
    void makeSound() override{
        cout<<"HAWK'S KEES"<<endl;
    }
    void fly() override{
        cout<<"HAWK SOARS"<<endl;
    }
};
int main() {
    Bird* ptr1; 
    Eagle eagle;
    Hawk hawk;
    ptr1 = &eagle;
    ptr1->makeSound();
    ptr1->fly();
    ptr1 = &hawk;
    ptr1->makeSound();
    ptr1->fly();
    return 0;
}