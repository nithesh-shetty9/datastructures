class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
   // Code here
        int left=solve1(arr,x);//samllest
        int right=solve2(arr,x);//largest and equal than x
        vector<int>ans;
        while(left>=0&&right<arr.size())
        {
            int leftdiff=abs(arr[left]-x);
            int rightdiff=abs(arr[right]-x);
            if(leftdiff<=rightdiff)
            {
                ans.push_back(arr[left]);
                left--;
                k--;
            }
            else
            {
                ans.push_back(arr[right]);
                right++;
                k--;
            }
            if(k==0)break;
        }
            while(left>=0&&k!=0)
            {
                ans.push_back(arr[left]);
                left--;
                k--;
            }
            while(right<arr.size()&&k!=0)
            {
                ans.push_back(arr[right]);
                right++;
                k--;
            }
            sort(ans.begin(),ans.end());
        return ans;;
    }
    int solve2(vector<int>&arr,int x)
    {
        int low=0;
        int ans=-1;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
              ans = mid;
              high = mid - 1;
            }
            else if(arr[mid]>x)
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
    int solve1(vector<int>&arr,int x)
    {
        int low=0;
        int ans=-1;
        int high=arr.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                high = mid - 1;
            }
            else if(arr[mid]>x)
            {
                high=mid-1;
            }
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};