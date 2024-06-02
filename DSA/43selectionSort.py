'''
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
This implementation of selection sort is unstable sort. Ex -
    4 2 4 1
    1 2 4[2nd] 4[0th] -> relative order of both 4 is changed
Other possible implementation
    4 2 4 1
    1 4 2 4
    1 2 4 4
    -> instead of swapping this implementation uses insertion at place of the element pushing back entire array
In place sort -> An in-place algorithm is an algorithm that does not need an extra space and produces an output in the same memory that contains the data by transforming the input 'in-place'. However, a small constant extra space used for variables is allowed.

'''
def selectionSort(arr,n):
    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if (arr[min] > arr[j]):
                min = j
        temp =  arr[i]
        arr[i] = arr[min]
        arr[min] = temp

def altSelectionSort(arr,n):
    for i in range(n-1):
        min = i
        for j in range(i+1,n):
            if (arr[min] > arr[j]):
                min = j
        arr.insert(i,arr[min])
        arr.pop(min+1)

# arr = [15,12,31,14]
arr = [5, 31, 5, 40, 44, 26, 48 ]
# selectionSort(arr,7)
altSelectionSort(arr,7)
print(arr)


