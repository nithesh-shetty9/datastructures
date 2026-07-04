class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int n=nums.size();
        int flip=0;
        int maxi=0;
        while(right<n)
        {
            if(nums[right]==0)
            {
                flip++;
            }
                while(flip>k)
                {
                    if(nums[left]==0)
                    flip--;
                    left++;
                }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
        
    }
};