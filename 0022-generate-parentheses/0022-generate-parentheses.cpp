class Solution {
public:
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       solve(n,n,"",ans);
       return ans; 
    }
    void solve(int open,int close,string temp,vector<string>&ans)
    {
        if(open==0&&close==0)
        {
            ans.push_back(temp);
            return;
        }
        if(open>0)
        {
            solve(open-1,close,temp+'(',ans);
        }
        if(close>open)
        {
            solve(open,close-1,temp+')',ans);
        }

    }
};