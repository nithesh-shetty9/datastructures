class Solution {
public:
    vector<int> nextGreaterElements(vector<int>&arr) {
          stack<int>st;
        int n=arr.size();
        vector<int>ans(n);
        for(int j=2*n-1;j>=0;j--)
        {
            int i=j%n;
            while(!st.empty()&&arr[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};