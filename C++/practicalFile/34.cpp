// 34.	WAP to implement multiple inheritance using public mode.
#include <iostream>
using namespace std;
class Parent1{
    public:
    void function(){
        cout<<"PARENT1 FUNCTION"<<endl;
    }
    void function1(){
        cout<<"PARENT1 FUNCTION1"<<endl;
    }
};
class Parent2{
    public:
    void function(){
        cout<<"PARENT2 FUNCTION"<<endl;
    }
    void function2(){
        cout<<"PARENT2 FUNCTION2"<<endl;
    }
};
class Derived : public Parent1,public Parent2{
    public:
    void functionD(){
        // function(); // ambiguous
        Parent1 :: function();
        Parent2 :: function();
    }
    void function2D(){
        function1();
        function2();
    }
    
};
int main() {
    Derived obj;
    obj.functionD();
    obj.function2D();
    // obj.function(); // ambiguous
    obj.Parent1::function();
    obj.Parent2::function();
    obj.function1();
    obj.function2();
    return 0;
}