// 8. Write a C++ program to create a class called Shape with methods called getPerimeter() and getArea(). Create a derived class called Circle that overrides the getPerimeter() and getArea() methods to calculate the area and perimeter of a circle.
#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void getArea(){
        cout<<"PLEASE SPECIFY A SHAPE"<<endl;
    }
    virtual void getPerimeter(){
        cout<<"PLEASE SPECIFY A SHAPE"<<endl;
    }
};
class Circle : public Shape{
    int r;
    void getRadius(){
        cout<<"ENTER RADIUS : ";
        cin>>r;
    }
    public:
    void getArea() override{
        getRadius();
        cout<<"AREA OF CIRCLE : "<<(3.14)*r*r<<endl;
    }
    void getPerimeter() override{
        getRadius();
        cout<<"PERIMETER OF CIRCLE : "<<2*(3.14)*r<<endl;
    }
};
int main() {
    Shape shape;
    Circle circle;
    shape.getArea();
    circle.getArea();
    shape.getPerimeter();
    circle.getPerimeter();
    return 0;
}