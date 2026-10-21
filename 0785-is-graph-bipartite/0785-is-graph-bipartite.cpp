class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        //2 different color for adjacent;
        vector<int>visited(adj.size(),-1);
        vector<int>track(adj.size(),0);//color 0 to to first node
        visited[0]=0;
        for(int i=0;i<adj.size();i++)
        {
            if(!track[i])
            {
                queue<int>q;
                q.push(i);
                   track[i]=1;
            while(!q.empty())
            {
            int curr=q.front();
            int color=visited[curr];
            q.pop();
            for(auto it:adj[curr])
            {
                if(!track[it])
                {
                    int c=color==0?1:0;
                    visited[it]=c;
                    track[it] = 1;
                    q.push(it);
                }
                else if(color==visited[it])
                {
                    return false;
                }
            }
        }
        }
        }
        return true;
    }
};