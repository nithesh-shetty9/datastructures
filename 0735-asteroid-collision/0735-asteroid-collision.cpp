class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
                bool alive=true;
                if(arr[i]<0)
                {
                while(!st.empty()&&st.top()>0&&st.top()<abs(arr[i]))
                {
                    st.pop();
                }
                if(!st.empty()&&st.top()==abs(arr[i]))
                {
                    st.pop();
                    alive=false;
                }
                else if(!st.empty()&&st.top()>abs(arr[i]))
                {
                    alive=false;
                }

            }cout<<alive<<endl;
            if(alive)st.push(arr[i]);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};