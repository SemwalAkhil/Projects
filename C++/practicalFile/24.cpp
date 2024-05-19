// 24.	WAP to show how to return object from function.
#include <iostream>
using namespace std;
int increment(int a){ return a+1;}
int main() {
    int num;
    cout<<"ENTER NUMBER : ";
    cin>>num;
    num = increment(num);
    cout<<"INCREMENTED VALUE IS : "<<num;
    return 0;
}