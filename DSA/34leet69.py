# 69. Sqrt(x)

# Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

# You must not use any built-in exponent function or operator.

# For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

# Example 1:

# Input: x = 4
# Output: 2
# Explanation: The square root of 4 is 2, so we return 2.
# Example 2:

# Input: x = 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        mid = 0
        high = x
        while (low <= high):
            mid = low + (high - low)//2
            if ((mid*mid) == x):
                return mid
            elif ((mid*mid) > x):
                mid = mid - 1
                high = mid
            else:
                low = mid + 1
        return mid

a = Solution() 
# print(a.mySqrt(4))
# print(a.mySqrt(2))
# print(a.mySqrt(8))
# print(a.mySqrt(24))
# print(a.mySqrt(7))
# print(a.mySqrt(6))
# print(a.mySqrt(5))
print(a.mySqrt(1))
