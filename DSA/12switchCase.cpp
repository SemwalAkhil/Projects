#include <iostream>
using namespace std;
int main() {
    int a,b,opr;
    cout<<"ENTER NUMBERS : ";
    cin>>a>>b;
    cout<<"ENTER OPERATION : (1) + (2) - (3) * (4) / : ";
    cin>>opr;
    switch (opr)
    {
    case 1:
        cout<<"ANSWER : "<<a+b<<endl;
        break;
    case 2:
        cout<<"ANSWER : "<<a-b<<endl;
        break;
    case 3:
        cout<<"ANSWER : "<<a*b<<endl;
        break;
    case 4:
        if (b!=0){
            cout<<"ANSWER : "<<a/b<<endl;
            break;
        }
        else{
            cout<<"ZERO DIVISION ERROR";
            break;
        }
    default:
        cout<<"INVALID OPERATION"<<endl;
        break;
    }
    return 0;
}