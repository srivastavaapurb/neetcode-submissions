class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int> v;
        while(l<r){
            if(nums[l]+nums[r]==target){
                v.push_back(l+1);
                v.push_back(r+1);
                break;
            }
            else if(nums[l]+nums[r]>target){
                r=r-1;
            }
            else{
                l+=1;
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};
