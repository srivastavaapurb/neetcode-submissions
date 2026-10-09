class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int reach=0;
        while(i<n-1){
            if(i>reach) break;
            reach=max(reach,i+nums[i]);
            if(reach>=n-1) return true;
            i++;
        }
        return n==1;
    }
};
