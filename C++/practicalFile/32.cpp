// 32.	WAP to implement multilevel inheritance using public mode.
#include <iostream>
using namespace std;
class Solution{
    public:
    int a;
    void setA(){
        cout<<"ENTER VALUE : ";
        cin>>a;
    }
    void getA(){
        cout<<"VALUE : "<<a<<endl;
    }
};
class Derived1 : public Solution{

};
class Derived2 : protected Derived1{

};
class Derived3 : private Derived2{

};
class Derived4 : public Derived3{

};
int main() {
    Solution a;
    Derived1 b;
    Derived2 c;
    Derived3 d;
    Derived4 e;
    a.setA();
    b.setA();
    // c.setA();
    // d.setA();
    // e.setA();
    cout<<"A ";
    a.getA();
    cout<<"B ";
    b.getA();
    // cout<<"C ";
    // c.getA(); // inaccessible
    // cout<<"D ";
    // d.getA(); // inaccessible
    // cout<<"E ";
    // e.getA(); // inaccessible
    return 0;
}