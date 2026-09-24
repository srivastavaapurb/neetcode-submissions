class Solution:
    def twoSum(self, arr: List[int], target: int) -> List[int]:
        nums=arr.copy()
        nums.sort()
        rp=len(nums)-1
        lp=0
        v=[]
        while(lp<rp):
            if(nums[lp]+nums[rp]==target):
                v.append(nums[lp])
                v.append(nums[rp])
                break;
            elif(nums[lp]+nums[rp]>target):
                rp-=1
            else:
                lp+=1
        m=[]
        for i in range(len(nums)):
            if(arr[i]==v[0] or arr[i]==v[1]):
                m.append(i)
        m.sort()
        return m
              