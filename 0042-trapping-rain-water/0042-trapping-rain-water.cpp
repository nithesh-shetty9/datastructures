class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        vector<int>left(n);
        vector<int>right(n);
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=max(temp,arr[i]);
            left[i]=temp;
        }
        temp=0;
        for(int i=n-1;i>=0;i--)
        {
            temp=max(temp,arr[i]);
            right[i]=temp;
        }
        for(int i=0;i<n;i++)
        {
            int mini=min(left[i],right[i]);
            ans+=mini-arr[i];
        }
        return ans;
    }
};