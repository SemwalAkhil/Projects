// 4. Write a C++ program to create a class called Employee with methods called work() and getSalary(). Create a derived class called HRManager that overrides the work() method and adds a new method called addEmployee().
#include <iostream>
using namespace std;
class Employee{
    public:
    virtual void work(){
        cout<<"EMPLOYEE IS WORKING"<<endl;
    }
    void getSalary(){
        cout<<"YOU GOT YOUR SALARY !!!"<<endl;
    }
};
class HRManager : public Employee{
    void addEmployee(){
        cout<<"EMPLOYEE ADDED"<<endl;
    }
    public:
    void work() override{
        cout<<"HR MANAGER IS WORKING"<<endl;
        addEmployee();
    }
};
int main() {
    Employee employee;
    HRManager hrmanager;
    employee.work();
    employee.getSalary();
    hrmanager.work();
    hrmanager.getSalary();
    return 0;
}