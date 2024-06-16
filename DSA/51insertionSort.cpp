/*
Problem statement
You are given 'N' integers in the form of an array 'ARR'. Print the sorted array using the insertion sort.

Insertion Sort iterates through the array and places each element in its correct position by shifting elements in the sorted part of the array.
    -> after each round we put one element from unsorted array to sorted part of array
    -> Time Complexity -> Worst Case -> O(n^2) -> reversed array -> each insertion requires shifting of all element
                       -> Best Case  -> O(n)   -> sorted array   -> no shifting or insertion required
    -> Space Complexity -> O(1) -> no additional space required
    -> Stable sorting algorithm
    -> In place sort
    -> Use Case -> Insertion sort is used when number of elements is small. It can also be useful when the input array is almost sorted, and only a few elements are misplaced in a complete big array.
*/
#include <iostream>
#include <vector>
using namespace std;
void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for (int i = 0 ;  i < n ; i++){
        int temp = arr[i];
        int j;
        iter1.push_back(i);
        for (j = i - 1 ; j >= 0; j--)
        {
            iter2.push_back(j);
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}
int main() {
    // vector<int> arr = {5, 31, 5, 40, 44, 26, 48};
    vector<int> arr = {6,5,4,3,2,1};
    insertionSort(arr.size(),arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}