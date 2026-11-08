class Solution {
    bool ispalindrome(int low,int high,string s)
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
        solve({},s,ans,0);
        return ans;
    }
    void solve(vector<string>temp,string s,vector<vector<string>>&ans,int index)
    {
        if(index==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispalindrome(index,i,s))
            {
               temp.push_back(s.substr(index,i-index+1));
                solve(temp,s,ans,i+1);
                temp.pop_back();
            }
        }
    }
};