//  ENTER A STRING ARRAY FROM THE USER AND PERFORM BUBBLE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> // For calculating exact time
#include <string>
using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; // To check if any swaps were made in the current pass
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap the strings if they are in the wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped in this pass, the array is already sorted
        if (!swapped) {
            break;
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

    // Start timing the bubble sort algorithm
    auto start = chrono::high_resolution_clock::now();

    // Perform bubble sort
    bubbleSort(arr, n);

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
