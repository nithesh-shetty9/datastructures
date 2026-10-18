class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        int i=0;
        while(i<s.size())
        {
            while(s[i]==' ')
            {
                i++;
            }
            string temp="";
            while(i<s.size()&&s[i]!=' ')
            {
                temp=temp+s[i];
                i++;
            }
            if(!temp.empty())
            {
            reverse(temp.begin(),temp.end());
            ans+=' '+temp;
            }
        }
        return ans.substr(1);
    }
};