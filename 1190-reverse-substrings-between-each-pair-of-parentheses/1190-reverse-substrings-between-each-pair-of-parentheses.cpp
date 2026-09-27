class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                 st.push(string(1, s[i]));;
            }
            else if(s[i]==')')
            {
               string word="";
               while(st.top()!="(")
               {
                word+=st.top();
                st.pop();
               }
               st.pop();
               reverse(word.begin(),word.end());
               st.push(word);
            }
            else
            {
                st.push(string(1, s[i]));;
            }
        }
         string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};