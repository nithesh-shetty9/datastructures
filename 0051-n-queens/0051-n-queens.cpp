class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
       if(n == 1)
    return {{"Q"}};
        vector<string>board;
       ;
for(int i=0;i<n;i++)
{
    board.push_back(string(n, '.'));
}
        solve(0,n,board,res);
        return res;
    }
    void solve(int col,int n,vector<string>&board,vector<vector<string>>&res)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(safe(board,i,col,n))
            {
                board[i][col]='Q';
                solve(col+1,n,board,res);
                board[i][col]='.';
            }
        }
    }
    bool safe(vector<string>&board,int row,int col,int n)
    {
        int dubrow=row;
        int dubcol=col;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        row=dubrow;
        col=dubcol;
        while(col>=0&&row<n)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
            row++;
        }
        row=dubrow;
        col=dubcol;
        while(row>=0&&col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
            row--;
        }
        return true;
    }
};