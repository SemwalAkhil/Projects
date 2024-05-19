// 9. Write a C++ program to create an abstract class Person with abstract methods eat() and exercise(). Create derived classes Athlete and LazyPerson that extend the Person class and implement the respective methods to describe how each person eats and exercises.
#include <iostream>
using namespace std;
class Person{
    public:
        virtual void eat() = 0;
        virtual void exercise() = 0;
};
class Athlete : public Person{
    public:
    void eat() override{
        cout<<"ATHLETE EATS A LOT"<<endl;
    }
    void exercise() override{
        cout<<"ATHLETE EXERCISES A LOT"<<endl;
    }
};
class LazyPerson : public Person{
    public:
    void eat() override{
        cout<<"LAZY PERSON MAY EAT A LOT"<<endl;
    }
    void exercise() override{
        cout<<"LAZY PERSON DOES NOT EXERCISES A LOT"<<endl;
    }
};
int main() {
    Person* ptr1; 
    Athlete athlete;
    LazyPerson lazyperson;
    ptr1 = &athlete;
    ptr1->eat();
    ptr1->exercise();
    ptr1 = &lazyperson;
    ptr1->eat();
    ptr1->exercise();
    return 0;
}