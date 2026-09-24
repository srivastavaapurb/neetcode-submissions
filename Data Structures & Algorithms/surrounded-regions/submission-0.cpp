class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<grid.size() && nrow>=0 && ncol<grid[0].size() && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // traverse first and last row, so keep counter for col
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]=='O'){
                dfs(0,j,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]=='O'){
                dfs(n-1,j,vis,grid);
            }
        }

        // traverse first and last col, so keep counter for row
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O'){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O'){
                dfs(i,m-1,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};
