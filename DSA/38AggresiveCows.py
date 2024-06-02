'''
Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
'''
def isPossible(stalls,k,midD):
    cowCount = 1
    lastPos = stalls[0]
    for i in range(len(stalls)):
        if ((stalls[i] - lastPos) >= midD):
            cowCount += 1
            lastPos = stalls[i]
        if (cowCount == k):
            return True
    return False
def aggressiveCows(stalls, k):
    # Write your code here.
    stalls.sort()
    minD,maxD,midD,ans = 0,0,0,-1
    maxD = max(stalls) - min(stalls)
    while (maxD >= minD):
        midD = minD + (maxD-minD)//2
        if (isPossible(stalls,k,midD)):
            minD = midD + 1
            ans = midD
        else:
            maxD = midD - 1
    return ans

stalls = [1,2,3]
print(aggressiveCows(stalls,2))