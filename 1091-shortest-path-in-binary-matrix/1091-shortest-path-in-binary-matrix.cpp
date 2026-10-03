class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        if(mat[0][0] == 1 || mat[m-1][n-1] == 1)
            return -1;

        if(m == 1 && n == 1)
            return 1;

        queue<pair<int,pair<int,int>>> q;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        q.push({1, {0, 0}});
        dist[0][0] = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty())
        {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if(row == m-1 && col == n-1)
                return d;

            for(int i = 0; i < 8; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   mat[nr][nc] == 0 &&
                   d + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = d + 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};