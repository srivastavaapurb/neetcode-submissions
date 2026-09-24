class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int j=0;j<m;j++){ // traverse first and last row, se keep col counter
            if(!vis[0][j] && grid[0][j]=='1'){
                dfs(0,j,vis,grid);
                cnt++;
            }
            if(!vis[n-1][j] && grid[n-1][j]=='1'){
                dfs(n-1,j,vis,grid);
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='1'){
                dfs(i,0,vis,grid);
                cnt++;
            }
            if(!vis[i][m-1] && grid[i][m-1]=='1'){
                dfs(i,m-1,vis,grid);
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;

    }
};
