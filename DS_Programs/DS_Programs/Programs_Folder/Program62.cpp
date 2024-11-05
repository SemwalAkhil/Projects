// ENTER A STRING ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.

#include <iostream>
#include <chrono> 
#include <string>
using namespace std;

void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void iterativeMergeSort(string arr[], int n) {
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = (left_start + curr_size - 1 < n - 1) ? left_start + curr_size - 1 : n - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? left_start + 2 * curr_size - 1 : n - 1;

            merge(arr, left_start, mid, right_end);
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

    iterativeMergeSort(arr, n);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Best Case Complexity: O(n log n) - Array is already sorted." << endl;
    cout << "Worst Case Complexity: O(n log n) - Array is in reverse order or unsorted." << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
