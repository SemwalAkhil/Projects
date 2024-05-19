/*
Problem statement
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.
*/
#include <iostream>
#include <vector>
using namespace std;
int isPossible(vector<int> &boards, int k,int mid){
    int count = 1;
    int distance = 0;
    for (int i = 0 ; i < boards.size() ; i++){
        if ((distance+boards[i]) <= mid){
            distance += boards[i];
        }
        else{
            count++;
            distance = boards[i];
            if ((count > k) || (boards[i] > mid)){
                return false;
            }
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    //    Write your code here.
    int low = 0;
    int mid = 0;
    int high = 0;
    int ans = -1;
    if (k > boards.size()){
        return ans;
    }
    for (int i = 0 ; i < boards.size() ; i++){
        high += boards[i];
    }
    while (low <= high){
        mid = low + (high-low)/2;
        if (isPossible(boards,k,mid)){
            high = mid - 1;    
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    cout<<findLargestMinDistance(boards,2)<<endl;
    return 0;
}