class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long cnt=0;
        algo(nums,0,nums.size()-1,cnt);
        return cnt;
    }
    void algo(vector<int>&arr,int low,int high,long long &cnt)
    {
        if(low>=high)return;
           int mid=low+(high-low)/2;
           algo(arr,low,mid,cnt);
           algo(arr,mid+1,high,cnt);
           mergeit(arr,low,mid,high,cnt);
    }
    void mergeit(vector<int>&arr,int low,int mid,int high,long long &cnt)
        {
            int l=low;
            int r=mid+1;
            while(l<=mid&&r<=high)
            {
                if(arr[l]>2*1LL*arr[r])
                {
                    cnt=cnt+(mid-l+1);
                    r++;
                }
                else
                {
                l++;
                }
            }



            int left=low;
            int right=mid+1;
            vector<int>temp;
            while(left<=mid&&right<=high)
            {
                if(arr[left]<=arr[right])
                {
                    temp.push_back(arr[left]);
                    left++;
                }
                else
                {
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while(left<=mid)
            {
                  temp.push_back(arr[left]);
                  left++;
            }
            while(right<=high)
            {
                temp.push_back(arr[right]);
                right++;
            }
            for(int i=low;i<=high;i++)
            {
                arr[i]=temp[i-low];
            }
        }
};