// 7. Write a C++ program to create a class known as Person with methods called getFirstName() and getLastName(). Create a derived class called Employee that adds a new method named getEmployeeId() and overrides the getLastName() method to include the employee's job title
#include <iostream>
using namespace std;
class Person{
    public:
    string fname,lname;
    virtual void getLastname(){
        cout<<"ENTER LAST NAME : ";
        cin>>lname;
    }
    void getFirstName(){
        cout<<"ENTER FIRST NAME : ";
        cin>>fname;
    }
    void displayInfo(){
        cout<<"EMPLOYEE : "<<fname<<" "<<lname<<endl;
    }
};
class Employee : public Person{
    int id;
    string job;
    public:
    void getLastname() override{
        cout<<"ENTER LAST NAME AND JOB : ";
        cin>>lname>>job;
    }
    void getEmployeeId(){
        cout<<"ENTER ID : ";
        cin>>id;
    }
    void displayInfo(){
        cout<<"EMPLOYEE "<<id<<" : "<<fname<<" "<<lname<<"("<<job<<")"<<endl;
    }
};
int main() {
    Person person;
    Employee employee1;
    person.getFirstName();
    person.getLastname();
    employee1.getFirstName();
    employee1.getLastname();
    employee1.getEmployeeId();
    person.displayInfo();
    employee1.displayInfo();
    return 0;
}