// ENTER A STRING ARRAY FROM THE USER AND PERFORM INSERTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
#include <string>
using namespace std;

// Recursive function to perform Insertion Sort
void recursiveInsertionSort(string arr[], int n) {
    // Base case: If the size is 1, the array is already sorted
    if (n <= 1) return;

    // Sort the first n-1 elements recursively
    recursiveInsertionSort(arr, n - 1);

    // Insert the last element at its correct position in the sorted array of n-1 elements
    string key = arr[n - 1];
    int j = n - 2;

    // Shift elements of arr[0..n-2] that are greater than key to one position ahead
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
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

    // Start timing the recursive insertion sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform recursive insertion sort
    recursiveInsertionSort(arr, n);

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
