// 33.	WAP to implement multiple inheritance using private mode.
#include <iostream>
using namespace std;
class Parent1{
    protected:
    void function(){
        cout<<"PARENT1 FUNCTION"<<endl;
    }
    void function1(){
        cout<<"PARENT1 FUNCTION1"<<endl;
    }
};
class Parent2{
    protected:
    void function(){
        cout<<"PARENT2 FUNCTION"<<endl;
    }
    void function2(){
        cout<<"PARENT2 FUNCTION2"<<endl;
    }
};
class Derived : private Parent1,private Parent2{
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
    return 0;
}