// 38.	WAP to implement virtual function.
#include <iostream>
using namespace std;
class Area{
    public:
    virtual void myFunc(){
        cout<<"THE AMOUNT OF SPACE WITHIN THE PERIMETER OF A TWO-DIMENSIONAL SHAPE"<<endl;
    }
};
class Square : public Area{
    public:
    void myFunc(){
        cout<<"SIDE X SIDE"<<endl;
    }
};
class Rectangle : public Area{
    public:
    void myFunc(){
        cout<<"LENGTH X BREADTH"<<endl;
    }
};
int main() {
    Area a;
    Square b;
    Rectangle c;
    a.myFunc();
    b.myFunc();
    c.myFunc();
    return 0;
}