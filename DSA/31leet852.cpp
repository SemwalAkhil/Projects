
// 852. Peak Index in a Mountain Array

// An array arr is a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
//   arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
//   arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high = arr.size() - 1;
        int low = 0;
        int mid = 0;
        while (high>low){
            mid = low + (high-low)/2;
            if (arr[mid] < arr[mid+1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return high;    
    }
};
/*
    6 7 8 9 5 4 3 2 1
    L       M       H
    L   M   H
         L/M H
        L/M/H
*/