class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            int temp=abs(arr[i]-x);
            if(pq.size()<k)
            {
                pq.push({temp,arr[i]});
            }
            else
            {
                if(temp<pq.top().first)
                {
                    pq.pop();
                    pq.push({temp,arr[i]});
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};