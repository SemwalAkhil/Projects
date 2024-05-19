// 37.	WAP to show the use of this pointer.
#include <iostream>
using namespace std;
class Solution{
    public:
    int a;
    Solution(){
        cout<<"VALUE : ";
        cin>>a;
    }
    int returnValue(){
        return this->a;
    }
    Solution* returnObject(){
        return this;
    }
    void displayValues(){
        cout<<"VALUE : "<<this->a<<endl;
    }
};
int main() {
    Solution obj1,obj2,obj3;

    cout<<"--------------------------------------------"<<endl;  
    cout<<"OBJ1 ";
    obj1.displayValues();
    cout<<"OBJ2 ";
    obj2.displayValues();
    cout<<"OBJ3 ";
    obj3.displayValues();
    
    obj2.a = obj1.returnValue();
    obj3 = obj1; 

    cout<<"--------------------------------------------"<<endl;  
    cout<<"OBJ1 ";
    obj1.displayValues();
    cout<<"OBJ2 ";
    obj2.displayValues();
    cout<<"OBJ3 ";
    obj3.displayValues();
    
    return 0;
}