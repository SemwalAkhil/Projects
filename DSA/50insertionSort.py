'''
Problem statement
You are given 'N' integers in the form of an array 'ARR'. Print the sorted array using the insertion sort.

Insertion Sort iterates through the array and places each element in its correct position by shifting elements in the sorted part of the array.
    -> after each round we put one element from unsorted array to sorted part of array
    -> Time Complexity -> Worst Case -> O(n^2) -> reversed array -> each insertion requires shifting of all element
                       -> Best Case  -> O(n)   -> sorted array   -> no shifting or insertion required
    -> Space Complexity -> O(1) -> no additional space required
    -> Stable sorting algorithm
    -> In place sort
    -> Adaptive algorithm -> if the data is already sorted, the algorithm will not reorder the elements. As a result, it reduces the number of iterations and improves execution speed.
        -> When the data is already sorted, it consumes less time. 
        -> They generally load faster.
        -> Improved execution speed.
    -> Use Case -> Insertion sort is used when number of elements is small. It can also be useful when the input array is almost sorted, and only a few elements are misplaced in a complete big array.
'''
from typing import List

# inefficient manner using pop and insert
# time complexity remains 0(n^2) but less efficient in practice because insert and pop can be expensive in terms of both time and space
# The space complexity is less optimal due to the use of insert and pop functions, which can result in additional memory overhead
def insertionSort1(n: int, arr: List[int]) -> None:
    # Write your code here.
    ind = 0
    sorted = 1
    for i in range(sorted,len(arr)):
        ele = arr[i]
        for j in range(sorted):
            if (arr[i] > arr[j]):
                ind += 1
        arr.insert(ind,arr.pop(i))
        ind = 0
        sorted += 1
        if (sorted == len(arr)):
            return    

# classic insertion sort
def insertionSort2(n: int, arr: List[int]) -> None:
    for i in range(1,len(arr)):
        temp = arr[i]
        j = i - 1
        while (j >= 0):
            if (arr[j] > temp):
                arr[j+1] = arr[j]
            else:
                break
            j -= 1
        arr[j+1] = temp

# arr = [5, 31, 5, 40, 44, 26, 48 ]
arr = [6, 5, 4, 3, 2, 1]
insertionSort1(7,arr)
print(arr)
insertionSort2(7,arr)
print(arr)