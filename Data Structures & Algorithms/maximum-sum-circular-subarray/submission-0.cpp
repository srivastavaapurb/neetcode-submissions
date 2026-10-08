class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int s1=0;
        int s2=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
            s1+=nums[i];
            maxi=max(maxi,s1);
            if(s1<0) s1=0;
            s2+=nums[i];
            mini=min(mini,s2);
            if(s2>0) s2=0;
        }
        if(maxi<0) return maxi;
        return max(maxi,total-mini);
    }
};