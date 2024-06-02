/*
Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.
You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

At ith round we put ith largest element at right place
Time complexity -> loop inside loop -> O(n^2)
                -> no. of comparisons : 1 + 2 + 3 ... (n - 2) + (n - 1) -> n(n-1)/2 comparisons -> O(n^2)
                -> constant space complexity : O(n^2)
                -> Best case: already sorted O(n)
                -> Worst case: reverse array O(n^2)
                -> stable sorting algorithm
                -> in place sort : An in-place algorithm is an algorithm that does not need an extra space and produces an output in the same memory that contains the data by transforming the input 'in-place'. However, a small constant extra space used for variables is allowed.
*/
#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swapped = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (!(swapped)){
            break;
        }
    }
    
}
int main() {
    vector<int> arr = {5, 31, 5, 40, 44, 26, 48};
    bubbleSort(arr,arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}