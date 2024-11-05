// Enter A String Array From The User And Perform Bubble Sort Algorithm Through Recursion. Also Calculate The Worst And Best Complexity With Exact Time.

#include <iostream>
#include <chrono> // For calculating exact time
#include <string>
using namespace std;

// Recursive function to perform Bubble Sort
void recursiveBubbleSort(string arr[], int n) {
    // Base case: If the size of the array is 1, it's already sorted
    if (n == 1) return;

    // Perform one pass of bubble sort, placing the largest element at the end
    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            // Swap the strings if they are in the wrong order
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    // If no elements were swapped in this pass, the array is already sorted
    if (!swapped) return;

    // Recursive call to sort the remaining array of size (n-1)
    recursiveBubbleSort(arr, n - 1);
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

    // Start timing the recursive bubble sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform recursive bubble sort
    recursiveBubbleSort(arr, n);

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
