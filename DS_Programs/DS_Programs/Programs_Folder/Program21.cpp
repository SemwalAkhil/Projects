// ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM BINARY SEARCH ALGORITHM THROUGH RECURSION

#include <iostream>
using namespace std;

void bubbleSort(string &str) {
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap characters if they are in the wrong order
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}


int binarySearch(const string &str, char target, int left, int right) {
    if (left > right)
        return -1;

    int mid = (right + left) / 2;

    if (str[mid] == target)
        return mid;

    if (str[mid] < target)
        return binarySearch(str, target, mid + 1, right);

    return binarySearch(str, target, left, mid - 1);
}

int main() {
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str);

    bubbleSort(str);

    cout << "Enter the character to search for: ";
    cin >> target;

    int result = binarySearch(str, target, 0, str.length() - 1);

    if (result != -1) {
        cout << "Character '" << target << "' found at index " << result << endl;
    } else {
        cout << "Character '" << target << "' not found in the string" << endl;
    }

    return 0;
}
