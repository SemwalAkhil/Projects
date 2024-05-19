// 36.	WAP to implement virtual base class.
#include <iostream>
using namespace std;
class Parent{
    public:
    void myFunc(){
        cout<<"PARENT FUNCTION"<<endl;
    }
};
class Derived1 : virtual public Parent{ };
class Derived2 : virtual public Parent{ };
class Final : public Derived1,public Derived2{ };
int main() {
    Final obj;
    obj.myFunc(); // if not using virtual base class myFunc ambigious to Parent, Derived1, Derived2
    return 0;
}