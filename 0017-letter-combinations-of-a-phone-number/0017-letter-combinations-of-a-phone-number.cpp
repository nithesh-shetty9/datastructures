class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string>mpp={
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
       }; 
       vector<string>ans;
       solve(0,ans,digits,"",mpp);
       return ans;
    }
    void solve(int index,vector<string>&ans,string &digits,string temp,
     vector<string>&mpp)
    {
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string word=mpp[digits[index]-'0'];
        for(int i=0;i<word.size();i++)
        {
            solve(index+1,ans,digits,temp+word[i],mpp);
        }
    }
};