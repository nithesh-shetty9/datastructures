class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string>res;
        solve(open,close,res,"");
        return res;
    }
    void solve(int open,int close,vector<string>&res,string temp)
    {
        if(close==0&&open==0)
        {
            res.push_back(temp);
            return;
        }
        if(open>0)
        {
            solve(open-1,close,res,temp+'(');
        }
        if(open<close)
        {
            solve(open,close-1,res,temp+')');
        }
    }

};