class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int low=0;
       int n=matrix.size();
       int m=matrix[0].size();
       int high=(m*n)-1;
       while(low<=high)
       {
        int mid=low+(high-low)/2;
        int ans=matrix[mid/m][mid%m];
        if(ans==target)return true;
        if(ans<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
       }
       return false;
    }
};