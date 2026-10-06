class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        int cost=prices[0];
        for(int i=0;i<n;i++){
            profit=max(profit,prices[i]-cost);
            cost=min(cost,prices[i]);
        }
        return profit;
    }
};
