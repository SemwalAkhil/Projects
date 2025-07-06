// generate all permutations of a string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    printf("Enter a string : ");
    cin >> str;
    sort(str.begin(), str.end());
    do
    {
        printf("%s\n", str.c_str());
    } while (next_permutation(str.begin(), str.end()));
}