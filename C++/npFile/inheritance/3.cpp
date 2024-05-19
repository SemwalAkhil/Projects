// 3. Write a C++ program to create a class called Shape with a method called getArea(). Create a derived class called Rectangle that overrides the getArea() method to calculate the area of a rectangle.
#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void getArea(){
        cout<<"PLEASE SPECIFY A SHAPE"<<endl;
    }
};
class Rectangle : public Shape{
    public:
    void getArea() override{
        int l,b;
        cout<<"ENTER DIMENSIONS : ";
        cin>>l>>b;
        cout<<"AREA OF RECTANGLE : "<<l*b<<endl;
    }
};
int main() {
    Shape shape;
    Rectangle rectangle;
    shape.getArea();
    rectangle.getArea();
    return 0;
}