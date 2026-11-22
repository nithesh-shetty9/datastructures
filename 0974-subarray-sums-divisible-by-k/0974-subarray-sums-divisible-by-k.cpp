class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int count=0;
        int sum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            int mod=(sum%k+k)%k;
            if(mpp.find(mod)!=mpp.end())
            {
                count+=mpp[mod];
            }
            mpp[mod]++;
        }
        return count;
    }
};