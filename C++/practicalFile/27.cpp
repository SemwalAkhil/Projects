// 27.	WAP to implement copy constructor.
#include <iostream>
using namespace std;
class Solution{
    int data;
    public:
    Solution(){
        data = 0;
    }
    // copy constructor
    Solution(const Solution& a){
        data = a.data;
    }
    void setData(){
        cout<<"ENTER DATA : ";
        cin>>data;
    }
    void getData(){
        cout<<"DATA : "<<data<<endl;
    }
    Solution returnObject(){
        return *this;
    }
};
int main() {
    Solution a,b,c;
    a.setData();

    b(a); //-> wrong way to call copy constructor

    // assigning return object to b
    b = a.returnObject();

    // explicit copying
    c = a;

    // displaying value
    cout<<"A ";
    a.getData();
    cout<<"B ";
    b.getData();
    cout<<"C ";
    c.getData();

    // initialising one object with other
    Solution d(a);
    cout<<"D ";
    d.getData();
    return 0;
}