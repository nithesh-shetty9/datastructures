class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int target=nums[nums.size()/2];
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
            {
                mpp[nums[i]]++;
            }
        if(mpp[target]>1)
        {
            return false;
        }
        return true;
    }
};