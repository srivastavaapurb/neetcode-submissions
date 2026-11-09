class Solution {
public:
    int m,n;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j]){
                ans=max(ans,1+dfs(x,y,dp,matrix));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxi=max(maxi,dfs(i,j,dp,matrix));
            }
        }
        return maxi;
    }
};
