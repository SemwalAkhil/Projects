// 9. Write a C++ program to create a vehicle class hierarchy. The base class should be Vehicle, with derived classes Truck, Car and Motorcycle. Each derived class should have properties such as make, model, year, and fuel type. Implement methods for calculating fuel efficiency, distance traveled, and maximum speed.
#include <iostream>
using namespace std;
class Vehicle{
    public:
    string make,model,fuel;
    int year;
    Vehicle(const string m,const string mo,const string f,const int y){
        make = m;
        model = mo;
        fuel = f;
        year = y;
    }
    int fuelEfficiency(){
        if (fuel == "Diesel"){
            cout<<"High Fuel Efficiency"<<endl;
            return 3;
        }
        else if (fuel == "Petrol"){
            cout<<"Low Fuel Efficiency"<<endl;
            return 2;
        }
        else{
            cout<<"Inefficient"<<endl;
            return 1;
        }
    }
    int maximumSpeed(){
        if (fuel == "Petrol"){
            cout<<"High Maximum Speed"<<endl;
            return 3;
        }
        else if (fuel == "Diesel"){
            cout<<"Low Maximum Speed"<<endl;
            return 2;
        }
        else{
            cout<<"Variable Speed"<<endl;
            return 1;
        }
    }
    void distanceTravelled(){
        int dist = (2025-year)*fuelEfficiency()*maximumSpeed()*3650; // Assuming vehicle travels 10 hour a day
        cout<<"Distance Travelled : "<<dist<<" Kms"<<endl; 
    }
};
class Truck : public Vehicle{
    public:
    Truck(string m,string mo,string f,int y) : Vehicle(m,mo,f,y){}
};
class Car : public Vehicle{
    public:
    Car(string m,string mo,string f,int y) : Vehicle(m,mo,f,y){}
};
class Motorcycle : public Vehicle{
    public:
    Motorcycle(string m,string mo,string f,int y) : Vehicle(m,mo,f,y){}
};
int main() {
    Truck truck("t","ruck","Diesel",2023);
    Car car("c","ar","Diesel",2020);
    Motorcycle motorCycle("motor","cycle","Petrol",2023);
    truck.distanceTravelled();
    car.distanceTravelled();
    motorCycle.distanceTravelled();
    return 0;
}