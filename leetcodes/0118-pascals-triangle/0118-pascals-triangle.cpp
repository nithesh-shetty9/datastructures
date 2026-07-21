class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=0;i<numRows;i++)
        {
            res.push_back(solve(i));
        }
        return res;
    }
    vector<int>solve(int r)
    {
        vector<int>temp;
        temp.push_back(1);
        int sum=1;
        for(int i=1;i<=r;i++)
        {
            sum=sum*(r-i+1);
            sum=sum/i;
            temp.push_back(sum);
        }
        return temp;
    }
};