// 23.	WAP to pass object as function argument using call by reference.
#include <iostream>
using namespace std;
void myFunc(int& value){
    // address same as in main
    cout<<"ADDRESS IN FUNCTION : "<<&value<<endl;
    cout<<"VALUE IS : "<<value<<endl;
}
int main() {
    int input;
    cout<<"ENTER A NUMBER : ";
    cin>>input;
    cout<<"ADDRESS IN MAIN : "<<&input<<endl;
    myFunc(input);
    return 0;
}