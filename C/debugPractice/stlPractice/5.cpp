// 5. Program to remove all occurrences of a given character from input String?
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    char c;
    printf("Enter a string : ");
    getline(cin, str); // avoid buffer entering to c
    printf("Character to be removed : ");
    cin >> c;
    auto rem = remove(str.begin(), str.end(), c);
    // The std::remove algorithm operates by shifting all elements that do not match the specified value (charToRemove) to the beginning of the range, maintaining their original order. It returns an iterator (newEnd) pointing to the new logical end of the range. The elements beyond this iterator remain in the container but are in a valid yet unspecified state.
    printf("String after rem : %s\n", str.c_str());
    str.erase(rem, str.end());
    printf("String after removing %c : %s", c, str.c_str());
}