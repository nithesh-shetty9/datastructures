class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>>ans;
      find(ans,nums,0);
      return ans;
    }
    void find(   vector<vector<int>>&ans,vector<int>& nums,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        set<int>sets;
        for(int i=index;i<nums.size();i++)
        {
            if(sets.find(nums[i])!=sets.end())
            {
                continue;
            }
            sets.insert(nums[i]);
            swap(nums[i],nums[index]);
            find(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
};