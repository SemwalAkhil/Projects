/*
Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++){
        if ((stalls[i]-lastPos) >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int max = stalls[stalls.size() - 1];
    int min = 0;
    int mid = 0;
    int ans = -1;

    while (max >= min){
        mid = min + (max-min)/2;
        if (isPossible(stalls,k,mid)){
            min = mid + 1;
            ans = mid;
        }
        else{
            max = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {1,2,3};
    cout<<aggressiveCows(stalls,2);
    return 0;
}