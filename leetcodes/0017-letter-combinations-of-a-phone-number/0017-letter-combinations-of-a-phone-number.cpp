class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>phone={
            " "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string>ans;
        solve(digits,ans,phone,0,"");
        return ans;
    }
    void solve(string &digits,vector<string>&ans,vector<string>&phone,int index,string temp)
    {
        if(index>=digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string dig=phone[digits[index]-'0'];
        for(int i=0;i<dig.size();i++)
        {
            solve(digits,ans,phone,index+1,temp+dig[i]);
        }

    }
};