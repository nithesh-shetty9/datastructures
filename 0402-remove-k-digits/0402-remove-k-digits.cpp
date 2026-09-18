class Solution {
public:
    string removeKdigits(string s, int k) {
        string temp="";
        stack<int>st;
        if(s.size()==k)return "0";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&k!=0&&s[i]<st.top())
            {
                k--;
                st.pop();
            }
            st.push(s[i]);
        }
        while(k>0)
        {
            k--;
            st.pop();
        }
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        string ans="";
        int index=-1;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='0')
            {
                index=i;
            }
            else
            {
                break;
            }
        }
        if(index==-1)return temp;
        ans=temp.substr(index+1);
        if(ans.empty())return "0";
        return ans;

    }
};