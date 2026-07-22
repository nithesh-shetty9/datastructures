class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            //check if front elemnt is slided
            if(!q.empty()&&q.front()<=i-k)
            {
                q.pop_front();
            }
            while(!q.empty()&&nums[i]>nums[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
            if(i+1>=k)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};