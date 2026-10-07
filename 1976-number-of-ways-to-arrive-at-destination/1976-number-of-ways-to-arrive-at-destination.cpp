class Solution {
public:
    int countPaths(int V, vector<vector<int>>&edges) {
         vector<vector<pair<long,long>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<long long>dist(V,LLONG_MAX);
        vector<long long>ways(V,0);
        ways[0]=1;
        dist[0]=0;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        pq.push({0,0});
        long long mod=1e9+7;
        while(!pq.empty())
        {
            long long  dis=pq.top().first;
            long long curr=pq.top().second;
            pq.pop();
            for(auto it:adj[curr])
            {
                long long  adjnode=it.first;
                long long adjdist=it.second;
                if(dis+adjdist<dist[adjnode])
                {
                    dist[adjnode]=dis+adjdist;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode]=ways[curr];
                }
                else if(dis+adjdist==dist[adjnode])
                {
                    ways[adjnode]=(ways[adjnode]+ways[curr])%mod;
                }
            }
        }
        return ways[V-1]%mod;
    }
};