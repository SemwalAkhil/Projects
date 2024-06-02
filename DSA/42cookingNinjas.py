'''
Problem statement
In Ninja Land, there is a famous restaurant named 'CookingNinjas'. There are 'N' cooks in 'CookingNinjas' numbered from 0 to N-1. Each cook has rank 'R' (1 <= R <= 10).

A cook with a rank 'R' can prepare 1 dish in the first 'R' minutes, 1 more dish in the next '2R' minutes, 1 more dish in next '3R' minutes, and so on (A cook can only make complete dishes) For example if a cook is ranked 2. He will prepare one dish in 2 minutes, one more dish in the next 4 mins and one more in the next 6 minutes hence in a total of 12 minutes he can make 3 dishes, Note, In 13 minutes also he can make only 3 dishes as he does not have enough time for the 4th dish).

One day 'CookingNinjas' receive an order of 'M' dishes that they need to complete as early as possible. You are given an integer array 'rank' of size 'N' in which 'rank[i]' gives 'rank' of ith cook and an integer 'M', You need to find out the minimum times required to complete this order of 'M' dishes.

Note
One dish can be prepared by only one cook, however, two or more cooks can simultaneously prepare different dishes.
For Example
Let 'N' = 4,  'ranks' = [1, 2, 3, 4] and 'M' = 11.  Then the minimum time required to cook 11 dishes will be 12 minutes.  The cooks should prepare dishes in the following manner -:
Cook-0 prepare 4 dishes in 10 minutes i.e (1 dish in 1 minute, 1 more dish in next 2 minutes, 1 more dish in next 3 minutes, 1 more dish in next 4 minutes).
Cook-1 prepare 3 dishes in 12 minutes i.e (1 dish in 2 minutes, 1 more dish in 4 minutes, 1 more dish in 6 minutes).
Cook-2 prepare 2 dishes in 9 minutes i.e (1 dish in 3 minutes, 1 more dish in the next 6 minutes).
Cook-3 prepare 2 dishes in 12 minutes i.e (1 dish in 4 minutes, 1 more dish in the next 8 minutes).
If all four cooks work simultaneously then they can prepare(4 + 3 + 2 + 2 = 11) dishes in 12 minutes. And it is the minimum possible time.
'''
from os import *
from sys import *
from collections import *
from math import *
            
def isPossible(rank,m,mid):
    time = 0
    count = 1
    dishCount = 0
    for i in range(len(rank)):                      
        while ((time+(rank[i]*count)) <= mid):
            time += rank[i]*count
            count += 1
            dishCount += 1
        time = 0
        count = 1
        if (dishCount >= m):
            return True
    return False


def minCookTime(rank, m):
    # Write your code here
    rank.sort()
    low,high,mid,ans = 0,(rank[-1]*m*m),0,-1
    while (low <= high):
        mid = low + (high - low)//2
        if (isPossible(rank,m,mid)):
            high = mid - 1
            ans = mid
        else:
            low = mid + 1
    return ans
    
ranks = [1,2,3,4]
print(minCookTime(ranks,11))
# 4 2 2 1