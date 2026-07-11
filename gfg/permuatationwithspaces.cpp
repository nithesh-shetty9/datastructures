class Solution {
  public:
  /*
  Given a string s, you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings.

Example 1:

Input:
s = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
  */

    vector<string> permutation(string s) {
        // Code Here
        vector<string>res;
        string temp="";
        temp=temp+s[0];
        int index=1;
        solve(res,s,temp,index);
        sort(res.begin(),res.end());
        return res;
    }
    void solve(vector<string>&res,string s,string temp,int index)
    {
        if(index>=s.size())
        {
            res.push_back(temp);
            return;
        }
        solve(res,s,temp+s[index],index+1);
         solve(res,s,temp+' '+s[index],index+1);
    }
};