#  Allocate Books

# Problem statement
# Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

# There are ‘m’ number of students, and the task is to allocate all the books to the students.

# Allocate books in such a way that:

# 1. Each student gets at least one book.
# 2. Each book should be allocated to only one student.
# 3. Book allocation should be in a contiguous manner.

# You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.

# If the allocation of books is not possible, return -1.

# Example:
# Input: ‘n’ = 4 ‘m’ = 2 
# ‘arr’ = [12, 34, 67, 90]

# Output: 113

# Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

# 12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

# 12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

# 12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

# We are getting the minimum in the last case.

# Hence answer is ‘113’.
 
def isPossible(arr,n,m,mid):
    studentCount = 1
    pageSum = 0
    for i in arr:
        if ((pageSum+i) <= mid):
            pageSum += i
        else:
            studentCount += 1
            pageSum = i
            if ((studentCount > m) or (i > mid)):
                return False
    return True

def findPages(arr, n: int, m: int) -> int:
    low,mid,high = 0,0,0
    ans = -1
    if (n >= m):
        for i in range(n):
            high += arr[i]
        while (low <= high):
            mid = low + (high-low)//2
            if (isPossible(arr,n,m,mid)):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
    return ans



# arr = [12, 34, 67, 90]
# print(findPages(arr,4,2))
arr = [1, 17, 14, 9, 15, 9, 14]
print(findPages(arr,7,7)) 
