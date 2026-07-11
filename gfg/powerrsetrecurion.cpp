class Solution {
  public:
  /*
  You are given a string. You need to return the power-set (in any order) of the string.
Note: The string s contains lowercase letter of alphabet.

Examples:
  */
    vector<string> powerSet(string s) {
        // code here
        vector<string>res;
        int index=0;
        solve(s,index,res,"");
        return res;
    }
    void solve(string s,int index,vector<string>&res,string temp)
    {
        if(index==s.size())
        {
            res.push_back(temp);
            return;
        }
        solve(s,index+1,res,temp+s[index]);
        solve(s,index+1,res,temp);
    }
};
