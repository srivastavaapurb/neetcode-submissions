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
        vector<int> temp1;
        vector<int> temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size()+1,-1);
        vector<int> dp2(temp2.size()+1,-1);
        int m1=f(0,temp1,dp1);
        int m2=f(0,temp2,dp2);
        return max(m1,m2);
    }
};
