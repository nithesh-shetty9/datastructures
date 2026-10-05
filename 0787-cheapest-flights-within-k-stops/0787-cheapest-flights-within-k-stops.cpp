class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
         for(int i=0;i<flights.size();i++)
         {
            adj[flights[i][0]].push_back({flights[i][1],
            flights[i][2]});
         }
         vector<int>dist(n,INT_MAX);

         queue<pair<int,pair<int,int>>>q;
         dist[src]=0;
         q.push({src,{0,0}});
         k=k+1;
         while(!q.empty())
         {
            int curr=q.front().first;
            int d=q.front().second.first;
            int stops=q.front().second.second;
            q.pop();
            for(auto it:adj[curr])
            {
                if(stops+1<=k&&d+it.second<dist[it.first])
                {
                    dist[it.first]=d+it.second;
                    q.push({it.first,{dist[it.first],stops+1}});
                }
            }
         }
         return dist[dst]==INT_MAX?-1:dist[dst];
    }
};