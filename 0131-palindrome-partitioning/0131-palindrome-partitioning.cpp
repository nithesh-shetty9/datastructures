class Solution {
    bool palindrome(string s,int low,int high)
    {
        while(low<=high)
        {
            if(s[low]!=s[high])return false;
            low++;
            high--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        solve(s,0,ans,{});
        return ans;
        
    }
     void solve(string &s,int idx,vector<vector<string>>&ans,
     vector<string>temp)
    {
        if(idx==s.size())
        {
           ans.push_back(temp);
           return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(palindrome(s,idx,i))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
};