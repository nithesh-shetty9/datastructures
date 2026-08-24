class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>>ans;
         int i=0;
         int n=intervals.size();
         bool flag=false;
         while(i<n)
         {
            if(!flag&&newInterval[0]<=intervals[i][0])
            {
                flag=true;
                ans.push_back(newInterval);
            }
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
         }
         if(!flag)
         {
            ans.push_back(newInterval);
         }
         vector<vector<int>>res;
         for(int i=0;i<ans.size();i++)
         {
            if(!res.empty()&&ans[i][0]<=res.back()[1])
            {
                res.back()[1]=max(res.back()[1],ans[i][1]);
            }
            else
            {
                res.push_back(ans[i]);
            }
         }
         return res;

    }
};