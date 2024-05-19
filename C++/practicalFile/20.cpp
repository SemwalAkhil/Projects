// 20.	WAP to show the use of static data members and static member functions.
#include <iostream>
using namespace std;
class Solution{
    string name;
    static int count;
    public:
    int experience;
    static void showCount(){
        // cout<<name; // returns error on trying to access other members
        // cout<<experience; // returns error on trying to access other members
        cout<<"TOTAL EMPLOYEES : "<<count<<endl;
    }
    void setEmployee(){
        cout<<"ENTER NAME : ";
        cin>>name;
        cout<<"ENTER EXPERIENCE : ";
        cin>>experience;
        count++;
    }
    void displayEmployee(){
        cout<<"NAME : "<<name<<endl;
        cout<<"EXPERIENCE : "<<experience<<endl;
    }
};
// initialising static data member
int Solution :: count = 0 ;
int main() {
    Solution a,b,c;
    a.setEmployee();
    b.setEmployee();
    c.setEmployee();
    cout<<"-------------------------------------------"<<endl;
    a.displayEmployee();
    b.displayEmployee();
    c.displayEmployee();
    a.showCount();
    return 0;
}