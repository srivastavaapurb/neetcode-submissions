class Solution {
private:
    int hours(int k, vector<int>& piles){
        int hrs=0;
        for(int i=0;i<piles.size();i++){
            hrs+=(piles[i]-1)/k + 1;
        }
        return hrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=(low+high)/2;
            int hrs=hours(mid,piles);
            if(hrs>h) low=mid+1;
            else high=mid;
        }
        return low;
    }
};
