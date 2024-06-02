/*
    Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

    You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.

    Time Complexity of selection sort 
        O(n - 1) * O( i+1 , i+2 , ... n)
        O(n) * O(n)
        O(n^2)
    Best Case -> sorted array -> O(n^2) -> no. of comparison remains same
    Worst Case -> reverrse sorted array -> O(n^2) -> no. of comparison remains same
    Space Complexity of selection sort O(1) because variables declaration done in constant space
    Use Case -> small array , vector or lists
*/

#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for (int i = 0 ; i < (n-1) ; i++){
        int minIndex = i;
        for (int j = i + 1 ; j < n ; j++ ){
            if (arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    
}
int main() {
    vector<int> arr = {5, 31, 5, 40, 44, 26, 48};
    selectionSort(arr,arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}