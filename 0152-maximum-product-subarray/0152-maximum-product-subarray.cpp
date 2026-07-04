class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int suffix=1;
        int prefix=1;
        int maxi=-11;
        int n=nums.size()-1;
        for(int i=0;i<=n;i++)
        {
            if(suffix==0)
            {
                suffix=1;
            }
            if(prefix==0)
            {
                prefix=1;
            }
            //remeber its multplying this subarray not adding
            prefix*=nums[i];
            suffix*=nums[n-i];
            maxi=max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};