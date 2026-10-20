class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
    int solve(vector<int>&nums,int k)
    {
        if(k<=0)return 0;
        int left=0;
        int right=0;
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mpp;
        int dist=0;
        while(right<n)
        {
            mpp[nums[right]]++;
            if(mpp[nums[right]]==1)dist++;
            while(dist>k)
            {
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)
                {
                    dist--;
                }
                left++;
            }
            cnt=cnt+(right-left+1);
            right++;
        }
        return cnt;
    }
};