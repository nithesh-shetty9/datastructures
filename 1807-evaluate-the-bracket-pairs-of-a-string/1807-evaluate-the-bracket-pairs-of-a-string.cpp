class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        string ans="";
        for(int i=0;i<knowledge.size();i++)
        {
            mpp[knowledge[i][0]]=knowledge[i][1];
        }
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if(s[i]=='(')
            {
                i++;
                string temp="";
                while(s[i]!=')')
                {
                    temp+=s[i];
                    i++;
                }
                if(mpp.count(temp))
                {
                    ans+=mpp[temp];
                }
                else
                {
                    ans+="?";
                }
            }
            else
            {
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};