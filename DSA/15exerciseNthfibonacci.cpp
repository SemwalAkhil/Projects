#include <iostream>
using namespace std;
/*
    return nth fibonacci term
    0 1 1 2 3 5 8 13 21
*/
int fibonacci(int n){
    if (n >= 0){
        int a = 0;
        int b = 1;
        for (int i = 1; i < n; i++)
        {
            int temp = a;
            a = b;
            b = b + temp;
        }
        return a;
    }
    return -1;
}
int main() {
    cout<<fibonacci(9)<<endl;
    return 0;
}