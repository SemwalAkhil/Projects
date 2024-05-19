// 3. Write a C++ program to create an abstract class Shape with abstract methods calculateArea() and calculatePerimeter(). Create derived classes Circle and Triangle that extend the Shape class and implement the respective methods to calculate the area and perimeter of each shape.
#include <iostream>
using namespace std;
class Shape{
    public:
        virtual void calculateArea() = 0;
        virtual void calculatePerimeter() = 0;
};
class Circle : public Shape{
    int r;
    void getRadius(){
        cout<<"Enter radius : ";
        cin>>r;
    }
    public:
        void calculateArea() override{
            getRadius();
            cout<<"Area is : "<<(3.14)*(r)*(r)<<endl;
        }
        void calculatePerimeter() override{
            getRadius();
            cout<<"Perimeter is : "<<2*(3.14)*(r)<<endl;
        }
};
class Triangle : public Shape{
    public:
        void calculateArea() override{
            int b,h;
            cout<<"Enter base : ";
            cin>>b;
            cout<<"Enter height : ";
            cin>>h;
            cout<<"Area is : "<<(0.5)*b*h<<endl;
        }
        void calculatePerimeter() override{
            int a,b,c;
            cout<<"Enter sides : ";
            cin>>a>>b>>c;
            cout<<"Perimeter is : "<<a+b+c<<endl;
        }
};
int main() {
    Shape* ptr1; 
    Circle circle;
    Triangle triangle;
    ptr1 = &circle;
    ptr1->calculateArea();
    ptr1->calculatePerimeter();
    ptr1 = &triangle;
    ptr1->calculateArea();
    ptr1->calculatePerimeter();
    return 0;
}