// ENTER A STRING ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
#include <string>
using namespace std;

// Function to partition the array
int partition(string arr[], int low, int high) {
    string pivot = arr[high]; // Choose the rightmost element as pivot
    int i = low - 1;          // Pointer for the greater element

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

// Iterative Quick Sort function without using the stack header
void iterativeQuickSort(string arr[], int n) {
    // Array to simulate the stack; it will hold pairs of low and high indices
    int stack[2 * n];
    int top = -1;

    // Push initial values of low and high to the stack
    stack[++top] = 0;  // low index
    stack[++top] = n - 1;  // high index

    // Keep popping from the stack while it's not empty
    while (top >= 0) {
        // Pop high and low
        int high = stack[top--];
        int low = stack[top--];

        // Perform partitioning
        int pivotIndex = partition(arr, low, high);

        // If there are elements on the left side of the pivot, push left side to stack
        if (pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }

        // If there are elements on the right side of the pivot, push right side to stack
        if (pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
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

    // Start timing the iterative quick sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform iterative quick sort
    iterativeQuickSort(arr, n);

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
