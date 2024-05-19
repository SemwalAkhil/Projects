# class Solution:
#     def findArrayIntersection(self,arr: list, n: int,brr: list, m: int):
#         retArr = []
#         start = 0
#         for i in range(n):
#             for j in range(start,m):
#                 if(arr[i] == brr[j]):
#                     retArr.append(arr[i])
#                     start += 1
#                     break
#                 elif (arr[i] < brr[j]):
#                     break
#                 start += 1
#         return retArr
#     def pairSum(self,arr, s):
#         retList = []
#         for i in range(len(arr)):
#             for j in range(i+1,len(arr)):
#                 if ((arr[i]+arr[j])==s):
#                     temp = [arr[i],arr[j]]
#                     temp.sort()
#                     retList.append(temp)
#         retList.sort()
#         return retList

# a = Solution()
# # arr = [1, 7, 8, 10, 11, 11, 12, 13, 13, 14, 14 ]
# # n = 11
# # m = 5
# # brr = [0, 1, 12, 13, 14] 
# # print(a.findArrayIntersection(arr,n,brr,m))
# # arr = a.pairSum([2,-3,3,3,-2],0)
# # print(arr)

# SORT 012 -------------------

# from os import *
# from sys import *
# from collections import *
# from math import *

# from sys import stdin,setrecursionlimit
# setrecursionlimit(10**7)

# def sort012(arr, n) :

# 	# write your code here
#     # don't return anything 
#     i = 0
#     j = 0
#     while (i < n):
#         i += 1
#         if (arr[j] == 0):
#             arr.pop(j)
#             arr.insert(0,0)
#         elif (arr[j] == 2):
#             arr.pop(j)
#             arr.append(2)
#             continue
#         j += 1
#     pass


# #taking inpit using fast I/O
# def takeInput() :
# 	n = int(input().strip())

# 	if n == 0 :
# 		return list(), 0

# 	arr = list(map(int, stdin.readline().strip().split(" ")))

# 	return arr, n



# def printAnswer(arr, n) :
    
#     for i in range(n) :
        
#         print(arr[i],end=" ")
        
#     print()
    
# #main

# arr = [0 ,1 ,2 ,2 ,1 ,0]
# n =6
# sort012(arr, n)
# printAnswer(arr, n)

# REVERSE ARRAY -----------------------------
# Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

# Example:

# We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
# based indexing so the subarray {5, 6} will be reversed and our 
# output array will be {1, 2, 3, 4, 6, 5}.

# def reverseArray(arr, m):
#     # Write your code here.
#     temp = []
#     for i in range(m+1,len(arr)):
#         temp.append(arr[i])
#     for i in range(len(arr)-m-1):
#         arr.pop()
#     temp.sort(reverse=True)
#     arr = arr+temp
#     return arr
#     pass

# print(reverseArray([10,9,8,7,6],2))

# UNIQUE OCCURENCES --------------------
# Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

# Example 1:

# Input: arr = [1,2,2,1,1,3]
# Output: true
# Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
def uniqueOccurrences(arr):
        counter = {}
        count = set()
        for i in arr:
            if i not in counter:
                counter[i] = 1
            else:
                counter[i] +=1
        for i in counter.values():
            if i in count:
                 return False
            else:
                count.add(i)
        return True

uniqueOccurrences([1,2])