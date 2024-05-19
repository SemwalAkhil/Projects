// 11.	WAP to swap two variables using function and using call by reference method.
#include <iostream>
using namespace std;
void swap(int& a,int& b){
    a += b;         // a -> 30
    b = a - b;      // b -> 10
    a = a - b;      // a -> 20
}
int main() {
    int a,b;
    cout<<"ENTER a : ";
    cin>>a;
    cout<<"ENTER b : ";
    cin>>b;
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    swap(a,b);
    cout<<"a : "<<a<<endl;
    cout<<"b : "<<b<<endl;
    return 0;
}