#include <iostream>
using namespace std;
/*
    fibonacci series
    0 1 1 2 3 5 8 13 21 ...
    nth term = (nth-1) term + (nth - 2) term

*/
int main() {
    int n = 10;
    int sum, a  = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0){
            cout<<a<<" ";
        }
        if (i == 1)
        {
            cout<<b<<" ";
        }
        if (i > 1){
            sum = a + b;
            a = b;
            b = sum;
            cout<<sum<<" ";
        } 
    }
    return 0;
}