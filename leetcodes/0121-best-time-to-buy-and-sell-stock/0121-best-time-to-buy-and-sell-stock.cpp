class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int mini=nums[0];
        int profit=0;
        for(int i=0;i<nums.size();i++)
        {
            mini=min(nums[i],mini);
            profit=max(profit,nums[i]-mini);
        }
        return profit;
    }
};