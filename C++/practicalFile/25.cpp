// 25.	WAP to implement friend function.
#include <iostream>
using namespace std;
class Solution{
    int value;
    void calc(){
        value += 1;
    }
    friend void assigner(Solution&);
    friend void caller(Solution);
};
void assigner(Solution& a){
    cout<<"ENTER VALUE : ";
    cin>>a.value; // accessing private member
}
void caller(Solution a){
    a.calc(); // accessing private member function
    cout<<"VALUE : "<<a.value<<endl;
}
int main() {
    Solution a;
    assigner(a);
    caller(a);
    return 0;
}