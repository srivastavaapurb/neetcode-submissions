class Solution {
private:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind>nums.size()-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+f(ind+2,nums,dp);
        int notpick=f(ind+1,nums,dp);
        int maxi=max(pick,notpick);
        return dp[ind]=maxi;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(0,nums,dp);
    }
};
