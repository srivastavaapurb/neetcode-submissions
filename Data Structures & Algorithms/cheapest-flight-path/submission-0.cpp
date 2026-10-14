class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,1e9);
        price[src]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e: flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push({0,src,0}); // stops,node,price
        while(!q.empty()){
            auto[stops,node,pri]=q.front();
            q.pop();
            if(stops>k) continue;
            for(auto it: adj[node]){
                int v=it.first;
                int wt=it.second;
                if(price[v]>pri+wt){
                    price[v]=pri+wt;
                    q.push({stops+1,v,price[v]});
                }
            }
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(price[i]!=1e9) ans[i]=price[i];
        }
        return ans[dst];
    }
};
