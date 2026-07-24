class Solution {
        vector<string>ans;
public:
    vector<string> letterCasePermutation(string s) {
        solve(s,0,"");
        return ans;
    }
    void solve(string s,int index,string temp)
    {
        if(index>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        if(s[index]>='0'&&s[index]<='9')
        {
            solve(s,index+1,temp+s[index]);
        }
        else
        {
            char temp1=tolower(s[index]);
            solve(s,index+1,temp+temp1);
            temp1=toupper(s[index]);
            solve(s,index+1,temp+temp1);
        }
    }
};