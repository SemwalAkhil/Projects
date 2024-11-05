// Enter an array from user and print all the palindrome numbers

#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Palindrome numbers in the array: ";
    for (int i = 0; i < n; ++i) {
        if (isPalindrome(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
