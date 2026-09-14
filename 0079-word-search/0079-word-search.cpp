class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(solve(board,i,j,word,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool solve(vector<vector<char>>& board,int row,
    int col,string word,int index)
    {
        if(row<0||col<0||row==board.size()||col==board[0].size())
        {
            return false;
        }
        if(word[index]!=board[row][col])return false;
        char temp=board[row][col];
        board[row][col]='#';
        index++;
        if(index==word.size())return true;
        bool found=solve(board,row+1,col,word,index)||
        solve(board,row-1,col,word,index)||solve(board,row,col+1,
        word,index)||solve(board,row,col-1,word,index);
        board[row][col]=temp;
        return found?true:false;

    }
};