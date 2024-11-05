//  ENTER A INTEGER ARRAY FROM THE USER AND PERFORM BUBBLE SORT ALGORITHM THROUGH RECURSION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME

#include <iostream>
#include <chrono> 
using namespace std;

void recursiveBubbleSort(int arr[], int n) {
    if (n == 1) return;

    bool swapped = false;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swapped = true;
        }
    }

    if (!swapped) return;

    recursiveBubbleSort(arr, n - 1);
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

    recursiveBubbleSort(arr, n);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Best Case Complexity: O(n) - Array is already sorted." << endl;
    cout << "Worst Case Complexity: O(n^2) - Array is in reverse order." << endl;
    cout << "Exact time taken for sorting: " << duration.count() << " seconds" << endl;

    return 0;
}
