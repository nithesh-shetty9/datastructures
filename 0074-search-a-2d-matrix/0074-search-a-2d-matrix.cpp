class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int m=matrix.size();
        int n=matrix[0].size();
        int high=(m*n)-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int loc=matrix[mid/n][mid%n];
            if(loc==target)return true;
            if(loc<target)
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