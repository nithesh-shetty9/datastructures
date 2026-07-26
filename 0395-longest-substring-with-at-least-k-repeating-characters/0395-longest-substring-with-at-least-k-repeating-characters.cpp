class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi=0;
        for(int targetunique=1;targetunique<=26;targetunique++)
        {
            vector<int>mpp(26,0);
        int uniques=0;
        int right=0;
        int n=s.size();
        int left=0;
        int count=0;
        while(right<n)
        {
            if(mpp[s[right]-'a']==0)
            {
                uniques++;
            }
            while(uniques>targetunique&&left<right)
            {
                if (mpp[s[left]-'a'] == k)
                count--;
                mpp[s[left]-'a']--;
                if(mpp[s[left]-'a']==0)
                {
                    uniques--;
                }
                left++;
            }
            mpp[s[right]-'a']++;
            if(mpp[s[right]-'a']==k)
            {
                count++;
            }
            if(count==uniques)
            {
                maxi=max(maxi,right-left+1);
                cout<<targetunique<<" "<<maxi<<endl;
            }
            right++;
        }
        }
        return maxi;

    }
};