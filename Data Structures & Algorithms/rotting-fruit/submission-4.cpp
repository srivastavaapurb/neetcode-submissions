class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        int cnt=0;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            for(int j=0;j<sz;j++){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            }
            if(!q.empty()) cnt++;
        }
        if(fresh==0) return cnt;
        return -1;
    }
};
