// 2.	WAP to generate the fibonacci  series up to a given number N.
#include <iostream>
using namespace std;
class Solution{
    public:
    void fibonacciIt(int num){
        int a = 0;
        int b = 1;
        int temp = 0;
        if (num >= 0 ){
            cout<<a<<endl;
        }
        for (b ; b <=  num ; b +=temp){
            temp = a;
            a = b;
            cout<<b<<endl;
        }
    }
};
int main(){
    Solution a;
    int num;
    cout<<"ENTER NUMBER OF MAX VALUE : ";
    cin>>num;
    a.fibonacciIt(num);
}