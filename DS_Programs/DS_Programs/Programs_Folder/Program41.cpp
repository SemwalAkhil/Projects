// Enter two arrays from the user and check they are same or not

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the arrays: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    bool areSame = true;
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            areSame = false;
            break;
        }
    }

    if (areSame) {
        cout << "The arrays are the same." << endl;
    } else {
        cout << "The arrays are not the same." << endl;
    }

    return 0;
}
