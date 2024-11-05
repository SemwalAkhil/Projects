// CALCULATE FACTORIAL OF A NUMBER USING RECURSION

#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1)
        return 1;
    // Recursive case
    else
        return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    // Check if the input is non-negative
    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << number << " is " << factorial(number) << endl;
    }

    return 0;
}
