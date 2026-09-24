class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxlen=0;
        int n=nums.size();
        long long sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        long long target=sum-x;
        if(target<0)return -1;
        if(target==0)return n;
        int right=0;
        int left=0;
        sum=0;
        while(right<n)
        {
            sum=sum+nums[right];
            while(sum>target)
            {
                sum=sum-nums[left];
                left++;
            }
            if(target==sum)
            {
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        if(maxlen==0)return -1;
        return n-maxlen;
    }
};