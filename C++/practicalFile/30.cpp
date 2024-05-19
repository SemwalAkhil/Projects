// 30.	WAP to implement single inheritance using public mode.
#include <iostream>
using namespace std;
class Solution{
    int a;
    public:
    void setA(){
        cout<<"ENTER VALUE : ";
        cin>>a;
    }
    void getA(){
        cout<<"VALUE : "<<a<<endl;
    }
};
class Derived : public Solution{
    int a;
};
int main() {
    Derived obj;
    obj.setA();
    obj.getA();
    return 0;
}