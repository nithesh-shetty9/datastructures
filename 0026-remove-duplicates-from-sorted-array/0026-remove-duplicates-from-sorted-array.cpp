class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr=nums[0];
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=curr)
            {
                j++;
                nums[j]=nums[i];
                curr=nums[i];
            }
        }
        return j+1;
    }
};