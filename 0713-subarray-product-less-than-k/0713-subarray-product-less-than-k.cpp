class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0; 
       long long sum=1;
        int right=0;
        int count=0;
        while(left<nums.size())
        {
            sum=sum*nums[left];
            while(sum>=k)
            {
                sum/=nums[right];
                right++;
            }
            count+=left-right+1;
            left++;
        }
        return count;
    }
};