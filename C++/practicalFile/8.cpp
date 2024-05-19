// 8.	WAP to show the use of scope resolution operator to access the global variables.
#include <iostream>
using namespace std;
int global = 10;
int main() {
    int global = 20;
    cout<<"LOCAL : "<<global<<endl;
    cout<<"GLOBAL : "<<::global<<endl;
    return 0;
}