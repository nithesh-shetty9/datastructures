class Solution {
public:
    string getHint(string s, string g) {
        vector<int>mpp(10,0);
         int n=s.size();
        vector<int>track(n,0);
        string res="";
        int count=0;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]-'0']++;
            if(s[i]==g[i])
            {
            track[i]=1;
             count++;
             mpp[s[i]-'0']--;
            }
        }
        res=res+to_string(count);
        res=res+"A";
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(track[i])
            {
                continue;
            }
            if(mpp[g[i]-'0']!=0)
            {
                t++;
                mpp[g[i]-'0']--;
            }
        }
        res=res+to_string(t);
        res=res+"B";

       return res;
    }
};