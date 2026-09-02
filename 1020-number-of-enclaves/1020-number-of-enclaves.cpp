class Solution {
public:
void dfs(vector<vector<int>>&grid,int row,int col,
      vector<vector<int>>&visited)
      {
          if(row<0||col<0||row==grid.size()||col==grid[0].size()||visited[row][col]
          ||grid[row][col]==0){
              return;
          }
          visited[row][col]=1;
          dfs(grid,row-1,col,visited);
          dfs(grid,row+1,col,visited);
          dfs(grid,row,col-1,visited);
          dfs(grid,row,col+1,visited);
      }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1&&!visited[0][i])
            {
                dfs(grid,0,i,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1]==1&&!visited[i][m-1])
            {
                dfs(grid,i,m-1,visited);
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            if(grid[n-1][i]==1&&!visited[n-1][i])
            {
                dfs(grid,n-1,i,visited);
            }
        }
         for(int i=n-1;i>=0;i--)
        {
            if(grid[i][0]==1&&!visited[i][0])
            {
                dfs(grid,i,0,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!visited[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};