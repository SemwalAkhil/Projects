//  ENTER A STRING ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
#include <string>
using namespace std;

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; ++i) {
        string key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of strings in the array: ";
    cin >> n;

    string arr[n];
    cout << "Enter the strings: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Start timing the insertion sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform insertion sort
    insertionSort(arr, n);

    // End timing
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Display time complexities
    cout << "Best Case Complexity: O(n) - Array is already sorted." << endl;
    cout << "Worst Case Complexity: O(n^2) - Array is in reverse order." << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
