class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int nrow=i+delrow[k];
                        int ncol=j+delcol[k];
                        if(nrow<0 || nrow>=n || ncol<0 || ncol>=m){
                            ans++;
                        }
                        else if(grid[nrow][ncol]==0) ans++;
                    }
                }
            }
        }
        return ans;
    }
};