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
def isPossible(stalls,k,mid):
    count = 1
    distance = 0
    for i in range(len(stalls)):
        if ((distance+stalls[i]) <= mid):
            distance += stalls[i]
        else:
            count += 1
            distance = stalls[i]
            if ((stalls[i] > mid) or (count > k)):
                return False
    return True
def aggressiveCows(stalls, k):
    # Write your code here.
    if (k > len(stalls)):
        return -1
    low,high,mid,ans = 0,0,0,-1
    for i in range(len(stalls)):
        high += stalls[i]
    while (high >= low):
        mid = low + (high-low)//2
        if isPossible(stalls,k,mid):
            high = mid - 1
            ans = mid
        else:
            low = mid + 1
    return ans

stalls = [1, 2, 3]
print(aggressiveCows(stalls,2))