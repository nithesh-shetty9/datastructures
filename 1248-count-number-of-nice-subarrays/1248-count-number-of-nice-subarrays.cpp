class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
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
            sum=sum+nums[right]%2;
            while(sum>goal)
            {
                sum=sum-nums[left]%2;
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};