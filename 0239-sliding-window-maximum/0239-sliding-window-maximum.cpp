class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int>q;
        deque<int>track;
        if(k>nums.size())
        {
            return {};
        }
        for(int i=0;i<k;i++)
        {
            if(track.empty())
            {
                track.push_back(nums[i]);
            }
            else
            {
                while(!track.empty()&&nums[i]>track.back())
                {
                        track.pop_back();
                }
                   track.push_back(nums[i]);
                }
            q.push(nums[i]);
        }
        vector<int>ans;
        ans.push_back(track.front());
        int n=nums.size();
        for(int i=k;i<n;i++)
        {
            if(track.front()==q.front())
            {
                track.pop_front();
            }
             while(!track.empty()&&nums[i]>track.back())
              {
                        track.pop_back();
              }
                track.push_back(nums[i]);
                ans.push_back(track.front());
                q.pop();
                q.push(nums[i]);
        }
        return ans;
    }
};