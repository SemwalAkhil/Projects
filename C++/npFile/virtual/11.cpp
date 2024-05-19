// 11. Write a C++ program to create an abstract class Shape2D with abstract methods draw() and resize(). Create derived classes Rectangle and Circle that extend the Shape2D class and implement the respective methods to draw and resize each shape
#include <iostream>
using namespace std;
class Shape2D{
    public:
        virtual void draw() = 0;
        virtual void resize() = 0;
};
class Rectangle : public Shape2D{
    public:
    void draw() override{
        cout<<"DRAWING RECTANGLE"<<endl;
    }
    void resize() override{
        cout<<"RESIZING RECTANGLE"<<endl;
    }
};
class Circle : public Shape2D{
    public:
    void draw() override{
        cout<<"DRAWING CIRCLE"<<endl;
    }
    void resize() override{
        cout<<"RESIZING CIRCLE"<<endl;
    }
};
int main() {
    Shape2D* ptr1; 
    Rectangle rectangle;
    Circle circle;
    ptr1 = &rectangle;
    ptr1->draw();
    ptr1->resize();
    ptr1 = &circle;
    ptr1->draw();
    ptr1->resize();
    return 0;
}