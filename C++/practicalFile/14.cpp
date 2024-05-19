// 14.	WAP to show the function overloading.
#include <iostream>
using namespace std;
class Shape{
    public:
    void area(int a,int b){
        cout<<"AREA OF SHAPE IS : "<<a*b<<endl;
    }
    void area(int a){
        cout<<"AREA OF SHAPE IS : "<<a*a<<endl;
    }
};
int main() {
    Shape shape;
    int length,breadth,side;
    
    cout<<"ENTER LENGTH OF RECTANGLE : ";
    cin>>length;
    cout<<"ENTER BREADTH OF RECTANGLE : ";
    cin>>breadth;
    shape.area(length,breadth);
    
    cout<<"ENTER SIDE OF SQUARE : ";
    cin>>side;
    shape.area(side);
    return 0;
}