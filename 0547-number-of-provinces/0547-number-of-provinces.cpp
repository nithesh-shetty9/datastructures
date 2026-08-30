class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>adj(V+1);
        vector<int>visited(V+1,0);
        int count=0;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1)
                {
               adj[i+1].push_back(j+1);
                }

            }
        }
        for(int i=1;i<=V;i++)
        {
            if(!visited[i])
            {
                count++;
                depth(adj,i,visited);
            }
        }
        return count;
    }
    void depth(vector<vector<int>>&adj,int node,vector<int>&visited)
    {
        visited[node]=1;
       for(auto it:adj[node])
       {
           if(!visited[it])
           {
               depth(adj,it,visited);
           }
       }
    }
};