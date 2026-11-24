class Solution {


    private:
    bool static cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
public:


    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums)
        {
            mpp[i]++;
        }
        vector<pair<int,int>>arr;
        for(auto it:mpp)
        {
            arr.push_back({it.second,it.first});
        }
        sort(arr.begin(),arr.end(),cmp);
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int size=arr[i].first;
            int num=arr[i].second;
            for(int j=0;j<size;j++)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};