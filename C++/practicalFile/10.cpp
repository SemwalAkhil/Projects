// 10.	WAP to swap two variables using function and using call by value method.
#include <iostream>
using namespace std;
void swap(int a,int b){
    a += b;
    b = a - b;
    a -= b;
    // since call by value hence changes made in function limited to function scope and does not affect value at original location
    cout<<"IN FUNCTION"<<endl;
    cout<<"A : "<<a<<" B : "<<b<<endl;
}
int main() {
    int a,b;
    cout<<"ENTER A : ";
    cin>>a;
    cout<<"ENTER B : ";
    cin>>b;
    cout<<"ORIGINAL"<<endl;
    cout<<"A : "<<a<<" B : "<<b<<endl;
    swap(a,b);
    cout<<"OUTSIDE FUNCTION"<<endl;
    cout<<"A : "<<a<<" B : "<<b<<endl;
    return 0;
}