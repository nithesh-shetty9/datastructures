class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>heal(grid.size(),vector<int>(grid[0].size(),
        INT_MAX));
        int m=grid.size();
        int n=grid[0].size();
        heal[0][0]=grid[0][0];
        pq.push({heal[0][0],{0,0}});
        int dc[4]={-1,1,0,0};
        int pc[4]={0,0,-1,1};
        while(!pq.empty())
        {
            int h=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==m-1&&col==n-1)
            {
                return h;
            }
            for(int i=0;i<4;i++)
            {
                int r=row+dc[i];
                int c=col+pc[i];
                int uh=h;
                if(r>=0&&c>=0&&r<m&&c<n)
                {
                    if(grid[r][c]==1)
                    {
                        uh=uh+1;
                    }
                   if(uh<heal[r][c])
                  {
                    heal[r][c]=uh;
                    pq.push({heal[r][c],{r,c}});
                   }
                }
            }
        }
        return -1;
    }
};