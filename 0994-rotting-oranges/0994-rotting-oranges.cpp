class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      vector<vector<bool>>visited(n,vector<bool>(m,false));
      int sec=0;
      queue<pair<int,int>>q;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                visited[i][j]=true;
                q.push({i,j});
            }
        }
      }
      while(!q.empty())
      {
        int size=q.size();
        bool flag=false;
        for(int i=0;i<size;i++)
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row-1>=0&&!visited[row-1][col]&&grid[row-1][col]==1)
            {
                flag=true;
                q.push({row-1,col});
                visited[row-1][col]=true;
            }
             if(row+1<n&&!visited[row+1][col]&&grid[row+1][col]==1)
            {
                flag=true;
                q.push({row+1,col});
                visited[row+1][col]=true;
            }
             if(col-1>=0&&!visited[row][col-1]&&grid[row][col-1]==1)
            {
                flag=true;
                q.push({row,col-1});
                visited[row][col-1]=true;
            }
             if(col+1<m&&!visited[row][col+1]&&grid[row][col+1]==1)
            {
                flag=true;
                q.push({row,col+1});
                visited[row][col+1]=true;
            }
        }
        if(flag)sec++;
      }
     for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1&&!visited[i][j])
            {
                return -1;
            }
        }
      }
      return sec; 
    }
};