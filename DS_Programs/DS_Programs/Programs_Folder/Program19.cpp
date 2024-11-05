// ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH ITERATION

#include <iostream>
#include <string>
using namespace std;

int linearSearch(const string &str, char target) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target) {
            return i;
        }
    }
    return -1; 
}

int main() {
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the character to search for: ";
    cin >> target;

    int result = linearSearch(str, target);

    if (result != -1) {
        cout << "Character '" << target << "' found at index " << result << endl;
    } else {
        cout << "Character '" << target << "' not found in the string" << endl;
    }

    return 0;
}
