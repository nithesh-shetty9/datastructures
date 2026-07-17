class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int temp=sum+nums[i];
            ans=max(ans,temp);
            if(temp<0)
            {
                sum=0;
            }
            else
            {
                sum=temp;
            }
        }
        return ans;
    }
};