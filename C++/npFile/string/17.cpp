// 17. Program to find all the permutations of a string
#include <iostream>
#include <string>
using namespace std;
int count = 0;
// Function to swap characters at positions i and j in the string
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}
// Recursive function to generate all permutations of a string
void permute(string str, int l, int r) {
    if (l == r) { // If the starting index (l) becomes equal to the ending index (r), it means we have reached a permutation
        count++;
        cout<<count<<" : "<<str<<endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // Swap current character with others
            permute(str, l + 1, r); // Recursively permute the remaining string
            swap(str[l], str[i]); // Backtrack: swap back to original order
        }
    }
}
int main() {
    string a = "hello";
    permute(a,0,a.length()-1);
    return 0;
}