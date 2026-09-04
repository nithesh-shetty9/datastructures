class Solution {
public:
    string reverseWords(string s) {
      string ans="";
      reverse(s.begin(),s.end());
      for(int i=0;i<s.size();i++)
      {
        string temp="";
        while(i<s.size()&&s[i]!=' ')
        {
            temp=temp+s[i];
            i++;
        }
        if(!temp.empty())
        {
            reverse(temp.begin(),temp.end());
            ans+=" "+temp;
        }
      }
      return ans.substr(1);  
    }
};