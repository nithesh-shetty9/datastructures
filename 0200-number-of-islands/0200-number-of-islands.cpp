class Solution {
private:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col)
    {
        if(row<0||col<0||row==grid.size()||col==grid[0].size()||visited[row][col]||
        grid[row][col]=='0')
        {
            return;
        }
        visited[row][col]=1;
        dfs(grid,visited,row,col+1);
        dfs(grid,visited,row,col-1);
        // dfs(grid,visited,row-1,col+1);
        // dfs(grid,visited,row+1,col+1);
        // dfs(grid,visited,row-1,col-1);
        // dfs(grid,visited,row+1,col-1);
        dfs(grid,visited,row+1,col);
        dfs(grid,visited,row-1,col);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
     int V=grid.size();
     int U=grid[0].size();
     vector<vector<int>>visited(V,vector<int>(U,0));
     int count=0;
     for(int i=0;i<V;i++)
     {
         for(int j=0;j<U;j++)
         {
             if(grid[i][j]=='1'&&!visited[i][j])
             {
                 count++;
                 dfs(grid,visited,i,j);
             }
         }
     }
     return count;
    }
};