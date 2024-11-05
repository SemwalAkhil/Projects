// ENTER A INTEGER ARRAY FROM THE USER, ENTER AN INTEGER VALUE AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION

#include <iostream>
using namespace std;

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if the left index exceeds the right, the target is not found
    if (left > right)
        return -1;

    // Calculate the middle index
    int mid = (right + left) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return binarySearch(arr, mid + 1, right, target);

    return binarySearch(arr, left, mid - 1, target);
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Enter the integer value to search for: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
