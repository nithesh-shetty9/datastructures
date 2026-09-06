class Solution {
public:
    int numberOfSubstrings(string s) {
        return solve(s,3)-solve(s,2);
    }
    int solve(string &s,int k)
    {
        if(k<0)return 0;
        unordered_map<int,int>mpp;
        int left=0;
        int right=0;
        int n=s.size();
        int count=0;
        while(right<n)
        {
            mpp[s[right]]++;
            if(mpp[s[right]]==1)k--;
            while(k<0)
            {
                mpp[s[left]]--;
                if(mpp[s[left]]==0)k++;
                left++;
            }
            count+=(right-left+1);
            right++;
        }
        return count;
    }
};