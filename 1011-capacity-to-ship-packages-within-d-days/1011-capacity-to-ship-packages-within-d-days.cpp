class Solution {
public:
    int shipWithinDays(vector<int>&arr, int days) {
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cnt=1;
            int sum=0;
            for(int i=0;i<arr.size();i++)
            {
                if(sum+arr[i]>mid)
                {
                    cnt++;
                    sum=arr[i];
                }
                else
                {
                    sum+=arr[i];
                }
            }
            if(cnt<=days)
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