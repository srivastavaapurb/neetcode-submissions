class Solution {
int f(int ind, vector<int>& cost, vector<int>& dp){
    if(ind>=cost.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int s1=cost[ind]+f(ind+1,cost,dp);
    int s2=cost[ind]+f(ind+2,cost,dp);
    int m = min(s1,s2);
    return dp[ind]=m;
}
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        int a=f(0,cost,dp);
        int b=f(1,cost,dp);
        return min(a,b);
    }
};
