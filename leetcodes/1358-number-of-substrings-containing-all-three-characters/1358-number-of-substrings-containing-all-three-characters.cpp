class Solution {
public:
    int numberOfSubstrings(string s) {
       return solve(s,3)-solve(s,2); 
    }
    int solve(string s,int k)
    {
        if(k<0)return 0;
        int left=0;
        int right=0;
        int n=s.size();
        int count=0;
        vector<int>hash(3,0);
        while(right<n)
        {
            hash[s[right]-'a']++;
            if(hash[s[right]-'a']==1)k--;
            while (k < 0) {
                hash[s[left] - 'a']--;
                if (hash[s[left] - 'a'] == 0)
                    k++;
                left++;
            }
                count+=(right-left+1);
            right++;
        }
        return count;
    }

};