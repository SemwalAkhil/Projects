// 8. Write a C++ program to create an abstract class Vehicle with abstract methods startEngine() and stopEngine(). Create derived classes Car and Motorcycle that extend the Vehicle class and implement the respective methods to start and stop the engines for each vehicle type.

#include <iostream>
using namespace std;
class Vehicle{
    public:
        virtual void startEngine() = 0;
        virtual void stopEngine() = 0;
};
class Car : public Vehicle{
    public:
    void startEngine() override{
        cout<<"CAR'S ENGINE STARTED"<<endl;
    }
    void stopEngine() override{
        cout<<"CAR'S ENGINE STOPPED"<<endl;
    }
};
class Motorcycle : public Vehicle{
    public:
    void startEngine() override{
        cout<<"MOTORCYCLE'S ENGINE STARTED"<<endl;
    }
    void stopEngine() override{
        cout<<"MOTORCYCLE'S ENGINE STOPPED"<<endl;
    }
};
int main() {
    Vehicle* ptr1; 
    Car car;
    Motorcycle motorcycle;
    ptr1 = &car;
    ptr1->startEngine();
    ptr1->stopEngine();
    ptr1 = &motorcycle;
    ptr1->startEngine();
    ptr1->stopEngine();
    return 0;
}