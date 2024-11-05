//  CALCULATE FIBONACCI OF A NUMBER USING RECURSION

#include <iostream>
using namespace std;

// Function to calculate Fibonacci using recursion
int fibonacci(int n) {
    // Base cases: Fibonacci of 0 is 0, Fibonacci of 1 is 1
    if (n <= 1)
        return n;
    // Recursive case
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    // Check if the input is non-negative
    if (number < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        cout << "Fibonacci of " << number << " is " << fibonacci(number) << endl;
    }

    return 0;
}
