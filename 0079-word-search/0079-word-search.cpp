class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      if (board.size() * board[0].size() < word.size())
    return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(solve(board,word,0,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool solve(vector<vector<char>>& board,string word,int track,int row,int col)
    {
         if(track==word.size())
        {
            return true;
        }
        if(row<0||row>=board.size()||col<0||col>=board[row].size())
        {
            return false;
        }
        if(board[row][col] != word[track])
    return false;
        char temp=board[row][col];
        board[row][col] = '#';
          bool found =
        solve(board, word, track+1, row-1, col) ||
        solve(board, word, track+1, row+1, col) ||
        solve(board, word, track+1, row, col+1) ||
        solve(board, word, track+1, row, col-1);

    board[row][col] = temp;

    return found;
    }
};