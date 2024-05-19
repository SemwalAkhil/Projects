// 10. Write a C++ program that creates a class hierarchy for employees of a company. The base class should be Employee, with derived classes Manager, Developer, and Programmer. Each derived class should have properties such as name, address, salary, and job title. Implement methods for calculating bonuses, generating performance reports, and managing projects.
#include <iostream>
using namespace std;
class Employee{
    public:
    string name,address,job;
    int salary;
    Employee(const string n,const string add,const string j,const int sal){
        name = n;
        address = add;
        job = j;
        salary = sal;
    }
    int projects(){
        int project;
        cout<<"Number of projects : ";
        cin>>project;
        cout<<"Projects : "<<project<<endl;
        return project;
    }
    int performance(){
        int num = projects();
        if (num > 15)
        {
            cout<<"High Performance"<<endl;
        }
        else if (num > 5){
            cout<<"Good Performance"<<endl;
            return 2;
        }
        else{
            cout<<"Low Performance"<<endl;
            return 1;
        }
        
    }
    void bonuses(){
        int bonus = performance()*3650; 
        cout<<"Bonus : Rs. "<<bonus<<endl; 
    }
};
class Manager : public Employee{
    public:
    Manager(string n,string add,string j,int sal) : Employee(n,add,j,sal){}
};
class Developer : public Employee{
    public:
    Developer(string n,string add,string j,int sal) : Employee(n,add,j,sal){}
};
class Programmer : public Employee{
    public:
    Programmer(string n,string add,string j,int sal) : Employee(n,add,j,sal){}
};
int main() {
    Manager manager("man","ager","manager",20000);
    Developer developer("devel","oper","developer",25000);
    Programmer programmer("pro","grammer","programmer",18000);
    manager.bonuses();
    developer.bonuses();
    programmer.bonuses();
    return 0;
}