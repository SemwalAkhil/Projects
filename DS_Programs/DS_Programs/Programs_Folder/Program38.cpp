// 13. Enter an array from user and count the duplicate values?

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int duplicateCount = 0;

    // Loop to find duplicates
    for (int i = 0; i < n; ++i) {
        bool isDuplicate = false;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j] && arr[i] != 0) {
                isDuplicate = true;
                arr[j] = 0;  // Mark duplicate as zero to avoid counting it again
            }
        }
        if (isDuplicate) {
            duplicateCount++;
        }
    }

    cout << "Total number of duplicate values: " << duplicateCount << endl;

    return 0;
}
