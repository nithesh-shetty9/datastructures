class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)count++;
            int temp=sum-k;
            if(mpp.find(temp)!=mpp.end())
            {
                count+=mpp[temp];
            }
            mpp[sum]++;
        }
        return count;
    }
};