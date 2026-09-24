class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)
        longest=1
        lastsmaller=float('-inf')
        cnt=0
        if n==0:
            return 0
        for i in range(n):
            if(nums[i]-1>lastsmaller):
                lastsmaller=nums[i]
                cnt=1
            if(nums[i]-1==lastsmaller):
                lastsmaller=nums[i]
                cnt+=1
            longest=max(longest,cnt)
    
        return longest        