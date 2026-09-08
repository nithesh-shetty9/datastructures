class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> colored(V, -1);
        queue<int> q;

        for(int i = 0; i < V; i++)
        {
            if(colored[i] != -1)
                continue;

            q.push(i);
            colored[i] = 0;

            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                for(auto it : graph[curr])
                {
                    if(colored[it] == -1)
                    {
                        colored[it] = colored[curr] == 0 ? 1 : 0;
                        q.push(it);
                    }
                    else
                    {
                        if(colored[it] == colored[curr])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};