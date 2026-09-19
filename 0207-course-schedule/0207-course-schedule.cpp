class Solution {
public:
    bool canFinish(int n, vector<vector<int>>&edges) {
               vector<int>ans;
                queue<int>q;
                vector<vector<int>>adj(n);
                vector<int>indegree(n,0);
                for(int i=0;i<edges.size();i++)
                {
                    indegree[edges[i][1]]++;
                    adj[edges[i][0]].push_back(edges[i][1]);
                }
                for(int i=0;i<n;i++)
                {
                    if(indegree[i]==0)
                    {
                        q.push(i);
                    }
                }
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();
                    ans.push_back(curr);
                    for(auto it:adj[curr])
                    {
                        indegree[it]--;
                        if(indegree[it]==0)q.push(it);
                    }
                }
            return ans.size()==n;
    }
};