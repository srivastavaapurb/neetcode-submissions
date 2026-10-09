class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& h){
        vis[r][c]=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nc>=0 && nc<h[0].size() && nr>=0 && nr<h.size() && h[nr][nc]>=h[r][c] && !vis[nr][nc]){
                dfs(nr,nc,vis,h);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dfs(0,j,pac,h);
            dfs(n-1,j,atl,h);
        }

        for(int i=0;i<n;i++){
            dfs(i,0,pac,h);
            dfs(i,m-1,atl,h);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
