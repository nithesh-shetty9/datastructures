class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans,{});
        return ans;
    }
    void solve(int index,vector<int>&nums,vector<vector<int>>&ans,vector<int>temp)
    {
        if(index==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1,nums,ans,temp);
        temp.pop_back();
        solve(index+1,nums,ans,temp);
    }
};