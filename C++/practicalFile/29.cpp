// 29.	WAP to show the use of destructor.
#include <iostream>
using namespace std;
class Solution{
    char* a;
    public:
    void setA(){
        a = new char[50];
        cout<<"ENTER NAME : ";
        cin>>a;
    }
    void getA(){
        cout<<"NAME : "<<a<<endl;
    }
    ~Solution(){
        cout<<"DESTRUCTOR CALLED FOR "<<a<<endl;
        delete[] a;
    }
};
int main() {
    Solution name;
    name.setA();
    name.getA();
    {
        Solution name2;
        name2.setA();
        name2.getA();
        // destructor called for name2
    }
    // destructor called for name1
    return 0;
}