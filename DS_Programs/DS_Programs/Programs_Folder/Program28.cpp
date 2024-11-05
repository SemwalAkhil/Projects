// Enter an array from user and copy the array into second array

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter " << n << " elements for the first array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    cout << "First array: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Copied array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
