class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int ans=-1;
        int low=0;
        int high=*max_element(arr.begin(),arr.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int flow=0;
            int bouq=0;
            for(int i=0;i<arr.size();i++)
            {
                if(arr[i]<=mid)
                {
                    flow++;
                }
                else
                {
                    flow=0;
                }
                if(flow==k)
                {
                    bouq++;
                    flow=0;
                }
            }
            if(bouq>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};