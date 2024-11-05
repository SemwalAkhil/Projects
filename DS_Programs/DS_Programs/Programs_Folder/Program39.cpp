// 14. Enter an array from user and print all possible combinations of the elements

#include <iostream>
using namespace std;

void printCombination(int arr[], int n, int start, int depth, int combination[], int r) {
    if (depth == r) {
        for (int i = 0; i < r; ++i) {
            cout << combination[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < n; ++i) {
        combination[depth] = arr[i];
        printCombination(arr, n, i + 1, depth + 1, combination, r);
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

    cout << "All possible combinations of elements:" << endl;
    for (int r = 1; r <= n; ++r) {
        int combination[r];
        printCombination(arr, n, 0, 0, combination, r);
    }

    return 0;
}
