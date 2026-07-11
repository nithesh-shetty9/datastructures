class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        solve(s,res,"",0);
         return res;
    }
    void solve(string s,vector<string>&res,string temp,int index)
    {
        if(index>=s.size())
        {
            res.push_back(temp);
            return;
        }
        if(!isdigit(s[index]))
        {
            char dh=tolower(s[index]);
            solve(s,res,temp+dh,index+1);
            char ch=toupper(s[index]);
            solve(s,res,temp+ch,index+1);
        }
        else
        {
            solve(s,res,temp+s[index],index+1);
        }
    }
};