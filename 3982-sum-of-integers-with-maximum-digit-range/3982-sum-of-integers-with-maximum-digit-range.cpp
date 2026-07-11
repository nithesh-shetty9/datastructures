class Solution {
    int solve(int num)
    {
        int low=10;
        int high=0;
        while(num>0)
        {
            int rem=num%10;
            low=min(low,rem);
            high=max(high,rem);
            num=num/10;
        }
        return high-low;
    }
public:
    int maxDigitRange(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            int diff=solve(nums[i]);
            maxi=max(maxi,diff);
        }
        long long res=0;
        for(int i:nums)
        {
            if(solve(i)==maxi)
            {
                res+=i;
            }
        }
        return res;
    }
};