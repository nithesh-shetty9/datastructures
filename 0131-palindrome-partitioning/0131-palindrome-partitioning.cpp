class Solution {
    bool ispalind(string &t,int left,int right)
    {

        while(left<=right)
        {
            if(t[left]!=t[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
public:
    vector<vector<string>> partition(string s) {
          vector<vector<string>>res;
          solve(s,res,{},0);
          return res;
    }
    void solve(string &s,vector<vector<string>>&res,vector<string>temp,int index)
    {
        if(index>=s.size())
        {
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispalind(s,index,i))
            {
                temp.push_back(s.substr(index,i-index+1));
                solve(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }
};