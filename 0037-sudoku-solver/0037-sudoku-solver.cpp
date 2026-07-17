class Solution {
public:
 bool row[9][10] = {};
bool col[9][10] = {};
bool box[9][10] = {};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')continue;
                int num=board[i][j]-'0';
                int b = (i / 3) * 3 + (j / 3);
                row[i][num]=true;
                col[j][num]=true;
                box[b][num]=true;
            }
        }
        solve(board);
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                {
                    int b=i/3*3+j/3;
                    for(int k=1;k<=9;k++)
                    {
                        if(!row[i][k]&&!col[j][k]&&!box[b][k]){
                          board[i][j]=k+'0';
                          row[i][k]=true;
                          col[j][k]=true;
                          box[b][k]=true;
                          if(solve(board))
                          {
                            return true;
                          }
                           board[i][j]='.';
                          row[i][k]=false;
                          col[j][k]=false;
                          box[b][k]=false; 

                        }

                    }
                    return false; 
                }
            }
        }
        return true;
    }
};
