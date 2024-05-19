#include <iostream>
#include <vector>
using namespace std;
/*
    9 9
    10 11 1 2 3 4 5 6 9 

    9 7
    5 6 7 8 9 10 0 2 3 


*/
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int high = n - 1;
    int low = 0;
    int mid;
    while (low <= high){
        mid = low + (high-low)/2;
        if (arr[0] < k)
        {
            if (arr[0] > arr[mid]){
                high = mid - 1;
            }
            else if (arr[mid] == k){
                return mid;
            }
            else if(arr[mid] > k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if (arr[0] > k)
        {
            if (arr[n-1] < arr[mid]){
                low = mid + 1;
            }
            else if (arr[mid] == k){
                return mid;
            }
            else if(arr[mid] > k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(arr[0] == k) { return 0;}
    }
    return -1;
}
int main(){
    vector<int> arr = {10, 11, 1, 2, 3, 4, 5, 6, 9};
    cout<<search(arr,9,9);
    // vector<int> arr = {5, 6, 7, 8, 9, 10, 0, 2, 3 };
    // cout<<search(arr,9,7);
    // vector<int> arr = {6, 7, 8, 9, 1, 2, 3, 4, 5 };
    // cout<<search(arr,9,2);
    // vector<int> arr = {6, 7, 8, 9, 1, 2, 3, 4, 5 };
    // cout<<search(arr,9,5);
    // vector<int> arr = {5,8,9,10,1,3,4};
    // cout<<search(arr,7,4);
    return 0;
}
/*
    TARGET - 9

    6 7 8 9 1 2 3 4 5
    L       M       H
    L M   H
       L/M H
        L/M/H
    
    TARGET - 2

    6 7 8 9 1 2 3 4 5
    L       M       H
              L M   H
             L/M H
    
    TARGET - 4

    5 8 9 10 1 3 4
    L      M     H
           L M   H
              L/M H
                L/M/H
*/