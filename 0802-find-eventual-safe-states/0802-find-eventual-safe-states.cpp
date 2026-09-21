class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int V=graph.size();
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        vector<int>safe(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,pathvisited,graph,safe);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(safe[i]==1)ans.push_back(i);
        }
        return ans;
    }
    bool dfs(int node,vector<int>&visited,vector<int>&pathvisited,
    vector<vector<int>>&adj,vector<int>&safe
    )
    {
        pathvisited[node]=1;
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,pathvisited,adj,safe))
                {
                    return true;
                }
            }
            else if(pathvisited[it])
            {
                return true;
            }
        }
        pathvisited[node]=0;
        safe[node]=1;
        return false;
    }
};