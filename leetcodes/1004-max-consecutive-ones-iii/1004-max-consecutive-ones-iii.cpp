class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int count=0;
        int n=nums.size();
        int maxi=0;
        while(right<n)
        {
            if(nums[right]==0)count++;
            while(count>k&&left<=right)
            {
                if(nums[left]==0)count--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};