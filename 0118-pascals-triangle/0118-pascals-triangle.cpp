class Solution {
    vector<int>findit(int n)
    {
        vector<int>temp;
        temp.push_back(1);
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*(n-i+1);
            ans=ans/i;
            temp.push_back(ans);
            
        }
        return temp;

    }


public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>>res;
         for(int i=0;i<numRows;i++)
         {
            res.push_back(findit(i));
         }
        return res;
    }
};