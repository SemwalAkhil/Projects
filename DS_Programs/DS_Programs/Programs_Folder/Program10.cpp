// CALCULATE THE SUM OF NATURAL NUMBERS TILL 10 USING RECURSION

#include <iostream>
using namespace std;

int sumOfNaturalNumbers(int n) {
    if (n <= 1)
        return n;
    else
        return n + sumOfNaturalNumbers(n - 1);
}

int main() {
    int number = 10;
    cout << "The sum of natural numbers till " << number << " is " << sumOfNaturalNumbers(number) << endl;
    return 0;
}
