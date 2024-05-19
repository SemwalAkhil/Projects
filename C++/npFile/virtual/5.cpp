// 5. Write a C++ program to create an abstract class Animal with abstract methods eat() and sleep(). Create derived classes Lion, Tiger, and Deer that extend the Animal class and implement the eat() and sleep() methods differently based on their specific behavior.

#include <iostream>
using namespace std;
class Animal{
    public:
        virtual void eat() = 0;
        virtual void sleep() = 0;
};
class Lion : public Animal{
    public:
    void eat() override{
        cout<<"LION'S EAT"<<endl;
    }
    void sleep() override{
        cout<<"LION'S SLEEP"<<endl;
    }
};
class Tiger : public Animal{
    public:
    void eat() override{
        cout<<"TIGER'S EAT"<<endl;
    }
    void sleep() override{
        cout<<"TIGER'S SLEEP"<<endl;
    }
};
class Deer : public Animal{
    public:
    void eat() override{
        cout<<"DEER'S EAT"<<endl;
    }
    void sleep() override{
        cout<<"DEER'S SLEEP"<<endl;
    }
};
int main() {
    Animal* ptr1; 
    Lion lion;
    Tiger tiger;
    Deer deer;

    ptr1 = &lion;
    ptr1->eat();
    ptr1->sleep();

    ptr1 = &tiger;
    ptr1->eat();
    ptr1->sleep();
    
    ptr1 = &deer;
    ptr1->eat();
    ptr1->sleep();
    return 0;
}