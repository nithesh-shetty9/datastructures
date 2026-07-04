class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        while(j<g.size()&&i<s.size())
        {
            if(s[i]>=g[j])
            {
              j++;
            }
            i++;
        }
        return j;
    }
};