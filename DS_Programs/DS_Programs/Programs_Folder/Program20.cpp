// ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH ITERATION

#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << "Enter the integer value to search for: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
