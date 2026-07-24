class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                st.push(arr[i]);
            }
            else
            {
                bool alive=true;
                while(alive&&!st.empty()&&st.top()>0)
                {
                 if(st.top()==abs(arr[i]))
                 {
                    alive=false;
                    st.pop();
                 }   
                 else if(abs(arr[i])>st.top())
                 {
                    st.pop();
                 }
                 else
                 {
                    alive=false;
                 }
                }
                if(alive)st.push(arr[i]);
            }
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