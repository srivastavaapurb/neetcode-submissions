class Solution {
int dfs(vector<vector<int>>& vis, int row, int col, vector<vector<int>>& grid){
    int cnt=1;
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    int delrow[]={1,0,-1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1){
            cnt+=dfs(vis,nrow,ncol,grid);
        }
    }
    return cnt;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int cnt=dfs(vis,i,j,grid);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
