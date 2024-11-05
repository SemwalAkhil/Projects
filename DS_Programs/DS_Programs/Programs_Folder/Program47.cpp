// ENTER A INTEGER ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
using namespace std;

// Recursive function for Selection Sort
void recursiveSelectionSort(int arr[], int n, int start = 0) {
    // Base case: If the starting index reaches the end of the array, sorting is complete
    if (start >= n - 1) return;

    // Find the minimum element in the unsorted part of the array
    int minIndex = start;
    for (int i = start + 1; i < n; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the found minimum element with the first element of the unsorted part
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Recursive call for the rest of the array
    recursiveSelectionSort(arr, n, start + 1);
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

    // Start timing the recursive selection sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform recursive selection sort
    recursiveSelectionSort(arr, n);

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
    cout << "Time Complexity (Best, Worst, Average): O(n^2)" << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
