class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                provinces++;
                bfs(i, isConnected, visited);
            }
        }

        return provinces;
    }

    void bfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {
                visited[node]=true;
                for(int i=0;i<isConnected.size();i++)
                {
                    if(!visited[i]&&isConnected[node][i]==1)
                    {
                        bfs(i,isConnected,visited);
                    }
                }
    }
};