class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& l){
        vis[node]=1;
        l.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,l);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> l;
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                dfs(i,adj,vis,l);
                cnt++;
            }
        }
        return cnt;
    }
};
