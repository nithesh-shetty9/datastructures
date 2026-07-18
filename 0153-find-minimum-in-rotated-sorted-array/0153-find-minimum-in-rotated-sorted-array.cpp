class Solution {
public:
    int findMin(vector<int>& nums) {
       return solve(nums,0,nums.size()-1); 
    }
    int solve(vector<int>&nums,int low,int high)
    {
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }

        }
        return nums[low];
    }
};