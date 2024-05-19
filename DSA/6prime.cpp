#include <iostream>
using namespace std;
/*
    check prime numbers
    2 3 5 7 11 13 17 19 23 29 31 37 ...
    number not multiple of any number except 1 and itself 
*/
int main() {
    int n = 100;
    for (int i = 2; i < (n/2); i++)
    {
        if ((n % i) == 0){
            cout<<"NOT PRIME";
            return 0;
        }
    }
    cout<<"PRIME";
    return 0;
}