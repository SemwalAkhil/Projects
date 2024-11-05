// CONVERT A NUMBER INTO BINARY USING RECURSION

#include <iostream>
using namespace std;

void convertToBinary(int n) {
    if (n == 0)
        return;

    convertToBinary(n / 2);
    cout << (n % 2);
}

int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Binary representation is not defined for negative numbers." << endl;
    } else if (number == 0) {
        cout << "Binary representation of 0 is 0" << endl;
    } else {
        cout << "Binary representation of " << number << " is ";
        convertToBinary(number);
        cout << endl;
    }

    return 0;
}
