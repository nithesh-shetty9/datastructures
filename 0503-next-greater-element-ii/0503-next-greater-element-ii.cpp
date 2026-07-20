class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(),0);
        int flag=-1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty()&&arr[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                flag=i;
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        for(int i=arr.size()-1;i>=flag;i--)
        {
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