//  Find the local minima in the array? (An element in an array is a local minima if it less than the element after it, and the element before it)

#include <iostream>
using namespace std;

void findLocalMinima(int arr[], int n) {
    cout << "Local minima in the array: ";
    bool foundMinima = false;

    // Check the first element separately if it's a local minima
    if (n > 1 && arr[0] < arr[1]) {
        cout << arr[0] << " ";
        foundMinima = true;
    }

    // Check for local minima in the middle elements
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            cout << arr[i] << " ";
            foundMinima = true;
        }
    }

    // Check the last element separately if it's a local minima
    if (n > 1 && arr[n - 1] < arr[n - 2]) {
        cout << arr[n - 1] << " ";
        foundMinima = true;
    }

    // If no local minima is found
    if (!foundMinima) {
        cout << "None";
    }

    cout << endl;
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

    findLocalMinima(arr, n);

    return 0;
}
