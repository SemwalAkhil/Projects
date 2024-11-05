// CALCULATE THE BEST AND WORST COMPLEXITY OF THE LINEAR SEARCHING ALGORITHM WITH EXACT TIME TAKEN BY THE ALGORITHM ON INTEGER ARRAY.\

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
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

    cout << "Enter the integer value to search for: ";
    cin >> target;

    auto start = high_resolution_clock::now();
    int result = linearSearch(arr, n, target);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    cout << "Time taken by linear search: " << duration.count() << " microseconds" << endl;

    return 0;
}
