// 7. Write a C++ program to create an abstract class Shape3D with abstract methods calculateVolume() and calculateSurfaceArea(). Create derived classes Sphere and Cube that extend the Shape3D class and implement the respective methods to calculate the volume and surface area of each shape
#include <iostream>
using namespace std;
class Shape3D{
    public:
        virtual void calculateVolume() = 0;
        virtual void calculateSurfaceArea() = 0;
};
class Sphere : public Shape3D{
    int r;
    void getRadius(){
        cout<<"Enter radius : ";
        cin>>r;
    }
    public:
        void calculateVolume() override{
            getRadius();
            cout<<"Volume is : "<<(4/3)*(3.14)*(r)*(r)*(r)<<endl;
        }
        void calculateSurfaceArea() override{
            getRadius();
            cout<<"Total Surface Area is : "<<4*(3.14)*(r)*(r)<<endl;
        }
};
class Cube : public Shape3D{
    int l,b,h;
    void getSides(){
        cout<<"Enter sides : ";
        cin>>l>>b>>h;
    }
    public:
        void calculateVolume() override{
            getSides();
            cout<<"Area is : "<<l*b*h<<endl;
        }
        void calculateSurfaceArea() override{
            getSides();
            cout<<"Perimeter is : "<<6*(l*b + b*h + h*l)<<endl;
        }
};
int main() {
    Shape3D* ptr1; 
    Sphere sphere;
    Cube cube;
    ptr1 = &sphere;
    ptr1->calculateVolume();
    ptr1->calculateSurfaceArea();
    ptr1 = &cube;
    ptr1->calculateVolume();
    ptr1->calculateSurfaceArea();
    return 0;
}