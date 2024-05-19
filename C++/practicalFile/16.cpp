// 16.	WAP to Implement Class with class function definitions outside the class
#include <iostream>
using namespace std;
class Solution{
    public:
    void sayHello();
};
void Solution :: sayHello(){
    cout<<"HELLO WORLD";
}
int main() {
    Solution a;
    a.sayHello();
    return 0;
}