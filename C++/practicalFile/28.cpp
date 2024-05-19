// 28. WAP to implement constructor overloading.
#include <iostream>
using namespace std;
class Solution{
    int area;
    public:
    Solution(int length, int breadth){
        area = length*breadth;
    }
    Solution(int side){
        area = side*side;
    }
    void displayArea(){
        cout<<"AREA : "<<area<<endl;
    }
};
int main() {
    int length,breadth,side;
    cout<<"AREA OF RECTANGLE"<<endl;
    cout<<"ENTER LENGTH : ";
    cin>>length;
    cout<<"ENTER BREADTH : ";
    cin>>breadth;
    Solution rect(length,breadth);
    rect.displayArea();
    cout<<"---------------------------------------------"<<endl;
    cout<<"AREA OF SQUARE"<<endl;
    cout<<"ENTER SIDE : ";
    cin>>side;
    Solution square(side);
    square.displayArea();
    return 0;
}