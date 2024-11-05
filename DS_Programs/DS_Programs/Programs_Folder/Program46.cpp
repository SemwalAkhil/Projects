//  ENTER A INTEGER ARRAY FROM THE USER AND PERFORM SELECTION SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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

    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr, n);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;


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
