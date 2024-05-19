// 3.	WAP to generate the fibonacci series of N numbers.
#include <iostream>
using namespace std;
class Solution{
    public:
    int fibonacciIt(int num){
        if (num <= 1){
            return num;
        }
        return fibonacciIt(num-1)+fibonacciIt(num-2);
    }
};
int main() {
    Solution a;
    int num;
    cout<<"ENTER NUMBER OF TERMS IN FIBONACCI SERIES : ";
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<a.fibonacciIt(i)<<endl;
    }
    return 0;
}