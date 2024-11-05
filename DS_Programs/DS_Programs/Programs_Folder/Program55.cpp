// ENTER A INTEGER ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as pivot
    int i = low - 1;       // Pointer for greater element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the pointer for greater element
            swap(arr[i], arr[j]); // Swap the elements
        }
    }
    swap(arr[i + 1], arr[high]); // Swap pivot to its correct position
    return i + 1; // Return the partitioning index
}

// Recursive Quick Sort function
void recursiveQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partition the array
        recursiveQuickSort(arr, low, pivotIndex - 1); // Sort the left half
        recursiveQuickSort(arr, pivotIndex + 1, high); // Sort the right half
    }
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

    // Start timing the recursive quick sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform recursive quick sort
    recursiveQuickSort(arr, 0, n - 1);

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
    cout << "Best Case Complexity: O(n log n) - Array is balanced after each partition." << endl;
    cout << "Worst Case Complexity: O(n^2) - Array is already sorted or in reverse order with unbalanced partitions." << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
