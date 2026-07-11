class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        solve(nums,res,target,{},0);
        return res;
    }
    void solve(vector<int>&nums,vector<vector<int>>&res,int target,vector<int>temp,int index)
    {
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        if(index==nums.size()||target<0)
        {
            return;
        }
        temp.push_back(nums[index]);
        solve(nums,res,target-nums[index],temp,index+1);
        temp.pop_back();
        int nextindex=index+1;
        while(nextindex<nums.size()&&nums[index]==nums[nextindex])
        {
            nextindex++;
        }
        solve(nums,res,target,temp,nextindex);
    }
};