// 12. Write a C++ program to create an abstract class GeometricShape with abstract methods area() and perimeter(). Create derived classes Triangle and Square that extend the GeometricShape class and implement the respective methods to calculate the area and perimeter of each shape
#include <iostream>
using namespace std;
class GeometricShape{
    public:
        virtual void area() = 0;
        virtual void perimeter() = 0;
};
class Square : public GeometricShape{
    int side;
    void getSide(){
        cout<<"Enter Side : ";
        cin>>side;
    }
    public:
        void area() override{
            getSide();
            cout<<"Area is : "<<side*side<<endl;
        }
        void perimeter() override{
            getSide();
            cout<<"Perimeter is : "<<4*side<<endl;
        }
};
class Triangle : public GeometricShape{
    public:
        void area() override{
            int b,h;
            cout<<"Enter base : ";
            cin>>b;
            cout<<"Enter height : ";
            cin>>h;
            cout<<"Area is : "<<(0.5)*b*h<<endl;
        }
        void perimeter() override{
            int a,b,c;
            cout<<"Enter sides : ";
            cin>>a>>b>>c;
            cout<<"Perimeter is : "<<a+b+c<<endl;
        }
};
int main() {
    GeometricShape* ptr1; 
    Square square;
    Triangle triangle;
    ptr1 = &square;
    ptr1->area();
    ptr1->perimeter();
    ptr1 = &triangle;
    ptr1->area();
    ptr1->perimeter();
    return 0;
}