//  Find the local maxima in the array? (An element in an array is a local maxima if it greater than the element after it, and the element before it)

#include <iostream>
using namespace std;

void findLocalMaxima(int arr[], int n) {
    cout << "Local maxima in the array: ";
    bool foundMaxima = false;

    // Check the first element separately if it's a local maxima
    if (n > 1 && arr[0] > arr[1]) {
        cout << arr[0] << " ";
        foundMaxima = true;
    }

    // Check for local maxima in the middle elements
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            cout << arr[i] << " ";
            foundMaxima = true;
        }
    }

    // Check the last element separately if it's a local maxima
    if (n > 1 && arr[n - 1] > arr[n - 2]) {
        cout << arr[n - 1] << " ";
        foundMaxima = true;
    }

    // If no local maxima is found
    if (!foundMaxima) {
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

    findLocalMaxima(arr, n);

    return 0;
}
