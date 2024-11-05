// ENTER A STRING ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> 
#include <string>
using namespace std;

void recursiveSelectionSort(string arr[], int n, int start = 0) {
    if (start >= n - 1) return;

    int minIndex = start;
    for (int i = start + 1; i < n; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    if (minIndex != start) {
        swap(arr[start], arr[minIndex]);
    }

    recursiveSelectionSort(arr, n, start + 1);
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

    auto start = chrono::high_resolution_clock::now();

    recursiveSelectionSort(arr, n);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Best Case Complexity: O(n^2) - Selection Sort has fixed time complexity." << endl;
    cout << "Worst Case Complexity: O(n^2) - Selection Sort has fixed time complexity." << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
