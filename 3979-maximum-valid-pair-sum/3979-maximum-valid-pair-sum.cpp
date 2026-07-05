class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        //its just a modifciation of stock market poriblem
        //here we track he largest nbehind and add to the current element if is big store it
        int maxi=nums[0];
        int result=0;
        for(int j=k;j<n;j++)
            {
             maxi=max(maxi,nums[j-k]);
                result=max(result,nums[j]+maxi);
            }
        return result;
    }
};