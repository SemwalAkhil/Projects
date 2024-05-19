// 26.	WAP to implement parameterized constructor.
#include <iostream>
using namespace std;
class Solution{
    int id;
    string name;
    public:
    Solution(int i, string n){
        id = i;
        name = n;
    }
    void display(){
        cout<<"EMPLOYEE ID : "<<id<<endl;
        cout<<"EMPLOYEE NAME : "<<name<<endl;
    }
};
int main() {
    int id;
    string name;
    cout<<"ENTER EMPLOYEE ID : ";
    cin>>id;
    cout<<"ENTER EMPLOYEE NAME : ";
    cin>>name;
    Solution a(id,name);
    a.display();
    return 0;
}