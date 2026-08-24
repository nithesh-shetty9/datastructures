class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>&nums) {
        sort(nums.begin(),nums.end());
        int end=nums[0][1];
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i][0]<end)
            {
                cnt++;
                end=min(end,nums[i][1]);
            }
            else
            {
                end=nums[i][1];
            }
        }
        return cnt;
    }
};