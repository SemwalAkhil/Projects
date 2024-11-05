// CALCULATE THE BEST AND WORST COMPLEXITY OF THE BINARY SEARCHING ALGORITHM WITH EXACT TIME TAKEN BY THE ALGORITHM ON INTEGER ARRAY

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function for binary search (iterative)
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (right + left) / 2;

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

    cout << "Enter the integer value to search for: ";
    cin >> target;

    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, target);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    cout << "Time taken by binary search: " << duration.count() << " microseconds" << endl;

    return 0;
}
