class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums=nums1+nums2
        nums.sort()
        n=len(nums)
        for i in range(n):
            if(n%2!=0):
                med=nums[n//2]
            else:
                med=(nums[n//2-1]+nums[n//2])/2
        return med       