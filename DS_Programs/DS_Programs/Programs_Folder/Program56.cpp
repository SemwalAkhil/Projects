// ENTER A STRING ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> 
#include <string>
using namespace std;

void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
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

    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr, n);

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
