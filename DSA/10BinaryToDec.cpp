#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int main() {
    /*
    123 -> 000001111011
        ->   100    +    20    +  3
        -> 01100100 + 00010100 + 0011
    321 -> 000101000001
    */
    int x = -123;
    int answer = 0;
    int digit = 0;
    int max = INT32_MAX;
    int min = INT32_MIN; 
    while ((x != 0) && (answer < max) && (answer > min))
    {
        answer *= 10;
        digit = x%10;
        answer += digit;
        x /= 10;
    }
    cout<<"REVERSED : "<<answer<<endl;
    
    return 0;
}