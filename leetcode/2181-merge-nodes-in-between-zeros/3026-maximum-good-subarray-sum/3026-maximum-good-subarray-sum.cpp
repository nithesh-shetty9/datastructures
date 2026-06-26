class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
       long long prefix=0;
       unordered_map<int,long long>mpp; 
       long long res=LLONG_MIN;
       for(int i=0;i<nums.size();i++)
       {
        prefix+=nums[i];
        long long temp1=nums[i]-k;
        long long temp2=nums[i]+k;
        if(mpp.find(temp1)!=mpp.end()){
          res = max(res, prefix - mpp[temp1]);
        }
          if(mpp.find(temp2)!=mpp.end()){
          res = max(res, prefix - mpp[temp2]);
        }
        if(mpp.find(nums[i])!=mpp.end())
        {
           mpp[nums[i]]=min(mpp[nums[i]],prefix-nums[i]);
        }
        else
        {
            mpp[nums[i]]=prefix-nums[i];
        }
       }
       return res== LLONG_MIN?0:res;
    }
};