class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
       priority_queue<pair<pair<int,int>,pair<int,int>>,
       vector<pair<pair<int,int>,pair<int,int>>>,
       greater<pair<pair<int,int>,pair<int,int>>>>pq;
        vector<vector<int>>heal(grid.size(),vector<int>(grid[0].size(),
        -1));
        int m=grid.size();
        int n=grid[0].size();
        heal[0][0]=k-grid[0][0];
        pq.push({{0,k-grid[0][0]},{0,0}});
        int dc[4]={-1,1,0,0};
        int pc[4]={0,0,-1,1};
        while(!pq.empty())
        {
            int dist=pq.top().first.first;
            int obst=pq.top().first.second;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==m-1&&col==n-1)
            {
                return dist;
            }
            for(int i=0;i<4;i++)
            {
                int r=row+dc[i];
                int c=col+pc[i];
                if(r>=0&&c>=0&&r<m&&c<n)
                {
                    int newob=obst;
                    if(grid[r][c]==1)
                    {
                        newob=obst-1;
                    }
                   if(newob>=0&&newob>heal[r][c])
                  {
                    heal[r][c]=newob;
                    pq.push({{dist+1,newob},{r,c}});
                   }
                }
            }
        }
        return -1; 
    }
};