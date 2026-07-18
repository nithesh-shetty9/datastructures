class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int n=nums.size()-1;
        int top=nums[n];
        nums[n]=-1;
        for(int i=n-1;i>=0;i--)
        {
            int prev=top;
             if(nums[i]>top)
            {
                prev=nums[i];
            }
            nums[i]=top;
            top=prev;
        }
        return nums;
    }
};