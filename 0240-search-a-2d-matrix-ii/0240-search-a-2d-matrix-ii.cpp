class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int col=m-1;
       int src=matrix[row][col];
       while(row<n&&col<m)
       {
        if(matrix[row][col]==target)return true;
        if(matrix[row][col]>target&&col-1>=0)
        {
            col--;
        }
        else if(matrix[row][col]<target&&row+1<n)
        {
            row++;
        }
        else
        {
            break;
        }
       }
       return false; 
    }
};