class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(len(nums1)-m):
            nums1.pop()
        for i in range(len(nums2)-n):
            nums2.pop()
        nums1 += nums2
        nums1.sort()
    def merge2(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i = 0
        j = 0
        while (j < n):
            if ((nums1[i] > nums2[j]) or (i == m+j)):
                nums1.insert(i,nums2[j])
                nums1.pop()
                j += 1
            else:
                i += 1
            

            
    

a = Solution()
nums = [1,2,3,4,0,0,0]
nums2 = [3,5,6]
a.merge2(nums,4,nums2,3)
print(nums)

'''
        1 2 3 4 0 0 0
        3 5 6
        i = 0 , j = 0
        1 2 3 4 0 0 0 -> i = 1 , j = 0
        1 2 3 4 0 0 0 -> i = 2 , j = 0
        1 2 3 3 4 0 0 -> i = 3 , j = 1
        1 2 3 3 4 0 0 -> i = 4 , j = 1
        1 2 3 3 4 5 0 -> i = 4 , j = 2
        1 2 3 3 4 5 0 -> i = 4 , j = 2
            


'''