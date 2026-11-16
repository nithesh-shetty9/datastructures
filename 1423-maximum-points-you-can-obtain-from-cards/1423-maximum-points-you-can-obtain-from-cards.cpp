class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0;
        int left=k-1;
        int n=nums.size();
        int right=n-1;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int ans=sum;
        while(left>=0)
        {
            sum=sum-nums[left];
            sum=sum+nums[right];
            cout<<sum;
            ans=max(ans,sum);
            left--;
            right--;
        }
        return ans;
    }
};