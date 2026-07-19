class Solution {
public:
    int largestRectangleArea(vector<int>&arr) {
        int n=arr.size();
        vector<int>prevsmaller(n,0);
        vector<int>nextsmaller(n,0);
        stack<int>st1;
        stack<int>st2;
        //prev smaller
        for(int i=0;i<n;i++)
        {
        while(!st1.empty()&&arr[i]<=arr[st1.top()])
        {
            st1.pop();
        }
        if(st1.empty())
        {
            prevsmaller[i]=-1;
        }
        else
        {
            prevsmaller[i]=st1.top();
        }
        st1.push(i);
        }
        //next smaller
        for(int i=n-1;i>=0;i--)
        {
        while(!st2.empty()&&arr[i]<=arr[st2.top()])
        {
            st2.pop();
        }
        if(st2.empty())
        {
            nextsmaller[i]=n;
        }
        else
        {
            nextsmaller[i]=st2.top();
        }
        st2.push(i);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            int temp=nextsmaller[i]-prevsmaller[i]-1;
            res=max(res,arr[i]*temp);
        }
        return res;
    }
};