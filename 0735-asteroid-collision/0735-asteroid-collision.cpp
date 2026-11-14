class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
               stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            bool isalive=true;
            if(arr[i]<0)
            {
              while(!st.empty()&&st.top()>0&&abs(arr[i])>st.top())
              {
                st.pop();
              }
              if(!st.empty()&&st.top()==abs(arr[i]))
              {
                isalive=false;
                st.pop();
              }
              if(!st.empty()&&st.top()>0&&abs(arr[i])<st.top())
              {
                isalive=false;
              }
                
            }
            if(isalive)st.push(arr[i]);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};