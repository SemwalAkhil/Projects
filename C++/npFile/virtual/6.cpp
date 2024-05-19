// 6. Write a C++ program to create an abstract class Employee with abstract methods calculateSalary() and displayInfo(). Create derived classes Manager and Programmer that extend the Employee class and implement the respective methods to calculate salary and display information for each role.

#include <iostream>
using namespace std;
class Employ{
    public:
        int salary;
        virtual void calculateSalary(int) = 0;
        virtual void displayInfo() = 0;
};
class Manager : public Employ{
    int tasks;
    public:
    void calculateSalary(int num) override{
        tasks = num;
        salary = tasks * 100;
    }
    void displayInfo() override{
        cout<<"You have completed "<<tasks<<" tasks hence your salary is "<<salary<<endl;
    }
};
class Programmer : public Employ{
    int programs;
    public:
    void calculateSalary(int num) override{
        programs = num;
        salary = programs * 100;
    }
    void displayInfo() override{
        cout<<"You have completed "<<programs<<" programs hence your salary is "<<salary<<endl;
    }
};
int main() {
    Employ* ptr1; 
    Manager manager;
    Programmer programmer;
    ptr1 = &manager;
    ptr1->calculateSalary(30);
    ptr1->displayInfo();
    ptr1 = &programmer;
    ptr1->calculateSalary(30);
    ptr1->displayInfo();
    return 0;
}