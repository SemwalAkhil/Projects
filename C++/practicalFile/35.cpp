// 35.	WAP to implement hybrid inheritance.
#include <iostream>
using namespace std;
class Base{
    public:
        string name;
        int roll;
        void getValue(){
            cout<<"ENTER NAME : ";
            getline(cin,name);
            cout<<"ENTER ROLL NO. : ";
            cin>>roll;
        }
};
class Derived1 : public virtual Base{
    public:
        int math;
        void getValue(){
            cout<<"MATHEMATICS MARKS : ";
            cin>>math;
        }
};
class Derived2 : public virtual Base{
    public:
        int sci;
        void getValue(){
            cout<<"SCIENCE MARKS : ";
            cin>>sci;
        }
};
class Result : public Derived1, public Derived2{
    public:
        void getResult(){
            Base::getValue();
            Derived1::getValue();
            Derived2::getValue();
        }
        void displayResult(){
            cout<<"RESULT OF : "<<name<<" ROLL NO. : "<<roll<<endl;
            cout<<"MATHEMATICS MARKS : "<<math<<" SCIENCE MARKS : "<<sci<<endl;
        }
};
int main() {
    Result abc;
    abc.getResult();
    abc.displayResult();
    return 0;
}