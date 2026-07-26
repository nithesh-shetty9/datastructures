class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>mpp1(26,0);
        vector<int>mpp2(26,0);
        vector<int>ans;
        for(char i:pat)
        {
            mpp2[i-'a']++;
        }
        int left=0;
        int right=0;
        int count=0;
        int m=pat.size();
        int n=txt.size();
        while(right<n)
        {
            mpp1[txt[right]-'a']++;
            if(right-left+1>m)
            {
                mpp1[txt[left]-'a']--;
                left++;
            }
            if(mpp1==mpp2)
            {
                ans.push_back(left);
            }
            right++;
        }
        return ans;  
    }
};