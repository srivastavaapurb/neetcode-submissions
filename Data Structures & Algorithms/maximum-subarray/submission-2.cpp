class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            s+=nums[i];
            maxi=max(maxi,s);
            if(s<0) s=0;
        }
        return maxi;

    }
};
