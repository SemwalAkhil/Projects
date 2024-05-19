#  You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



#  Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



#  Note :
#  1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
#  2. 'arr' may contain duplicate elements.


#  Example:
#  Input: 'arr' = [0,1,1,5] , 'k' = 1

#  Output: 1 2

#  Explanation:
#  If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

def firstAndLastPosition(arr, n, k):
     
    high = n - 1
    low = 0
    ret = -1
    while (low <=high):
        mid = low+(high-low)//2
        if (arr[mid] == k):
            ret = mid
            high = mid - 1
        elif (arr[mid] > k):
            high = mid - 1
        else:
            low = mid + 1
    return ret

arr = [1,2,3,4,5]
print(firstAndLastPosition(arr,5,3))