//  You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



//  Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



//  Note :
//  1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
//  2. 'arr' may contain duplicate elements.


//  Example:
//  Input: 'arr' = [0,1,1,5] , 'k' = 1

//  Output: 1 2

//  Explanation:
//  If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

#include <bits/stdc++.h> 
#include <vector>
#include <iostream>
using namespace std;
int firstOcc(vector<int>& arr, int n, int k);
int lastOcc(vector<int>& arr, int n, int k);
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair <int,int> temp;
    temp.first = firstOcc(arr,n,k);
    temp.second = lastOcc(arr,n,k);
    return temp;
}
int firstOcc(vector<int>& arr,int n,int k){
    int high = n - 1;
    int low = 0;
    int mid = 0;
    int ret = -1;
    while (low<=high){
        mid = low+((high-low)/2);
        if (arr[mid] == k){
            ret = mid;
            high = mid -1;       
        }
        else if (arr[mid] > k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ret;
}
/*
    target - 1

    0 1 1 2 3 4 5
    L     M     H
    L M   H     -> RET 1
   L/H 
*/
int lastOcc(vector<int>& arr,int n,int k){
    int high = n - 1;
    int low = 0;
    int mid = 0;
    int ret = -1;
    while (low<=high){
        mid = low+((high-low)/2);
        if (arr[mid] == k){
            ret = mid;
            low = mid + 1;       
        }
        else if (arr[mid] > k){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ret;
}
/*
    target - 1

    0 1 1 2 3 4 5
    L     M     H
    L M   H     -> RET 1
      L M H     -> RET 2
         L/H 
*/
int main(){
    vector<int> arr = {0,1,1,2,3,4,5};
    pair<int,int> temp = firstAndLastPosition(arr,7,1);
    cout<<temp.first<<endl;
    cout<<temp.second<<endl;
    return 0;
}