// 40.	WAP to implement binary operator overloading.
#include <iostream>
using namespace std;
class Solution{
    int data;
    public:
    Solution(){
        cout<<"ENTER DATA : ";
        cin>>data;
    }
    void operator+(const Solution& a){
        data += a.data;
    }
    void operator-(const Solution& a){
        data -= a.data;
    }
    void operator*(const Solution& a){
        data *= a.data;
    }
    void operator/(const Solution& a){
        data /= a.data;
    }
    void display(){
        cout<<"DATA : "<<data<<endl;
    }
};
int main() {
    Solution a,b;
    a+b;
    cout<<"A+B"<<endl;
    cout<<"A ";
    a.display();
    cout<<"B ";
    b.display();

    a-b;
    cout<<"A-B"<<endl;
    cout<<"A ";
    a.display();
    cout<<"B ";
    b.display();

    
    b*a;
    cout<<"B*A"<<endl;
    cout<<"A ";
    a.display();
    cout<<"B ";
    b.display();

    
    b/a;
    cout<<"B/A"<<endl;
    cout<<"A ";
    a.display();
    cout<<"B ";
    b.display();
    return 0;
}