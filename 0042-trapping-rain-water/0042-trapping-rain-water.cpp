class Solution {
public:
    int trap(vector<int>& arr) {
           int res=0;
        vector<int>next(arr.size(),0);
        vector<int>prev(arr.size(),0);
        int n=arr.size();
        int ne=0;
        for(int i=0;i<n;i++)
        {
            ne=max(ne,arr[i]);
            next[i]=ne;
        }
        ne=0;
        for(int i=n-1;i>=0;i--)
        {
            ne=max(ne,arr[i]);
            prev[i]=ne;
        }
        int total=0;
        for(int i=0;i<arr.size();i++)
        {
            total+=(min(next[i],prev[i])-arr[i]);
        }
        return total;
    }
};