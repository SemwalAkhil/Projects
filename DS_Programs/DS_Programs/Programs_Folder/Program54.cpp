// ENTER A INTEGER ARRAY FROM THE USER AND PERFORM QUICK SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <stack> // For using an iterative stack-based approach
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

// Iterative Quick Sort function
void iterativeQuickSort(int arr[], int n) {
    stack<pair<int, int>> stack; // Stack to store low and high indexes

    // Push initial values of low and high to the stack
    stack.push({0, n - 1});

    // Keep popping from the stack while it's not empty
    while (!stack.empty()) {
        int low = stack.top().first;
        int high = stack.top().second;
        stack.pop();

        // Perform partitioning
        int pivotIndex = partition(arr, low, high);

        // If there are elements on the left side of the pivot, push left side to stack
        if (pivotIndex - 1 > low) {
            stack.push({low, pivotIndex - 1});
        }

        // If there are elements on the right side of the pivot, push right side to stack
        if (pivotIndex + 1 < high) {
            stack.push({pivotIndex + 1, high});
        }
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
