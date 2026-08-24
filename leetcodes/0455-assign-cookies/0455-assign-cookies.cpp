class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int n=g.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(j>=s.size())
            {
                return j;
             }
            if(s[j]>=g[i])
            {
                j++;
            }
        }
        return j;
      
    }
};