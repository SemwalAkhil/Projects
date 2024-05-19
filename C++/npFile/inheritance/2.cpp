// 2. Write a C++ program to create a class called Vehicle with a method called drive(). Create a derived class called Car that overrides the drive() method to print "Repairing a car".
#include <iostream>
using namespace std;
class Vehicle{
    public:
    virtual void drive(){
        cout<<"VEHICLE DRIVING"<<endl;
    }
};
class Car : public Vehicle{
    public:
    void drive() override{
        cout<<"REPAIRING CAR"<<endl;
    }
};
int main() {
    Vehicle vehicle;
    Car car;
    vehicle.drive();
    car.drive();
    return 0;
}