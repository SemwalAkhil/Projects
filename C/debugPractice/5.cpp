// Program to Remove Duplicate Element in an array
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
vector<int> removeDuplicates(vector<int> vec)
{
    unordered_set<int> set;
    vector<int> newVec;
    for (auto &&i : vec)
    {
        if (set.insert(i).second)
        {
            newVec.push_back(i);
        }
    }
    return newVec;
}
int main()
{
    vector<int> vec = {1, 2, 2, 3, 4, 5, 5, 5, 5, 6, 7, 0};
    vec = removeDuplicates(vec);
    for (auto &&i : vec)
    {
        printf("%d ", i);
    }
}