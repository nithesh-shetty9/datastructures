class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
                dfs(0,i,board,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(i,0,board,visited);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
            {
                dfs(i,m-1,board,visited);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[n-1][i]=='O')
            {
                dfs(n-1,i,board,visited);
            }
        }


        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(board[i][j]=='O'&&!visited[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited)
    {
        if(row<0||col<0||row==board.size()||col==board[0].size()||visited[row][col]||board[row][col]!='O')
        {
            return;
        }
        visited[row][col]=1;
       dfs(row-1,col,board,visited);
       dfs(row+1,col,board,visited);
       dfs(row,col-1,board,visited);
       dfs(row,col+1,board,visited);
    }
};