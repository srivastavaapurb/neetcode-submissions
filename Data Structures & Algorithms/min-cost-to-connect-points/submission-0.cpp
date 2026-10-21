class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,0,-1});
        int sum=0;
        vector<pair<int,int>> mst;
        while(!pq.empty()){
            auto[wt,node,parent]=pq.top();
            pq.pop();
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            if(parent!=-1) mst.push_back({parent,node});
            for(auto it: adj[node]){
                int adjnode=it.first;
                int edwt=it.second;
                if(!vis[adjnode]) pq.push({edwt,adjnode,node});
            }
        }
        return sum;
    }
};
