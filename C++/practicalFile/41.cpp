// 41.	WAP to implement Exception Handling.
#include <iostream>
using namespace std;
void divide(int a, int b){
    try
    {
        if (b==0){
            throw "DIVISION BY ZERO";
        }
        a = a/b;
        cout<<a<<endl;
        
    }
    catch(const char* e)
    {
        cerr<< e << endl;
    }
}
int main() {
    int a,b;
    cout<<"ENTER DIVIDEND : ";
    cin>>a;
    cout<<"ENTER DIVISOR : ";
    cin>>b;
    divide(a,b);
    return 0;
}