class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return solve(nums,0,nums.size()-1,target);   
    }
    int solve(vector<int>&nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};