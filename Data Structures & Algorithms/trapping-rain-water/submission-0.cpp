class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        int left=0;
        int right=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(left<right){
            if(heights[left]<=heights[right]){
                lmax=max(lmax,heights[left]);
                ans+=lmax-heights[left];
                left++;
            }
            else{
                rmax=max(rmax,heights[right]);
                ans+=rmax-heights[right];
                right--;
            }
        }
        return ans;
    }
};
