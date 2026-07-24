class Solution {
public:
vector<string>ans;
    vector<string> validStrings(int n) {
        solve(n,0,"");
        return ans;
    }
    void solve(int n,int index,string temp)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        if(index==0||temp[index-1]=='1')
        {
            solve(n,index+1,temp+'0');
            solve(n,index+1,temp+'1');
        }
        else 
        {
            solve(n,index+1,temp+'1');
        }
    }
};