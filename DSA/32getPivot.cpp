/*
    Given a sorted array [1,2,3,4,5,6,7]
    rotated array may be [6,7,1,2,3,4,5]
    In this rotated array you have to find the pivot point such that
    arr[pivot-1]>arr[pivot]<arr[pivot+1] 
*/

#include <iostream>
using namespace std;
int getPivot(int arr[],int len){
    int high = len - 1;
    int low = 0;
    int mid = 0;
    while (high > low){
        mid = low + (high-low)/2;
        if (arr[mid] >= arr[0]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return high;
}
int main(){
    int arr[] ={6,7,8,9,1,2,3,4,5};
    cout<<getPivot(arr,9)<<endl;
    return 0;
}
/*
    6 7 8 9 1 2 3 4 5
    L       M       H       -> H = M
    L   M   H               -> L = M+1
         L/M H              -> L = M+1
          L/M/H          
*/