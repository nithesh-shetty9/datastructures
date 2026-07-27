class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
    int solve(vector<int>&nums,int goal)
    {
        if(goal<0)return 0;
        int count=0;
        int left=0;
        int sum=0;
        int right=0;
        int n=nums.size();
        while(right<n)
        {
            sum=sum+nums[right];
            while(sum>goal)
            {
                sum=sum-nums[left];
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};