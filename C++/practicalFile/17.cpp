// 17.	WAP to Implement nesting of member functions.
#include <iostream>
using namespace std;
class Solution{
    public:
    int add(int a, int b) {
        // Nested member function to calculate the sum
        auto calculateSum = [](int x, int y) {
            return x + y;
        };
        return calculateSum(a,b);
    }
    void displaySum(int a,int b) {
        // calling one member function inside other
        cout << "Result: " <<add(a,b)<< endl;
    }
};
int main() {
    Solution obj;
    int a,b;
    cout<<"ENTER A : ";
    cin>>a;
    cout<<"ENTER B : ";
    cin>>b;
    obj.displaySum(a,b);
    return 0;
}