class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int left=0;
        int start=0;
        int right=0;
        int n=s.size();
        for(char i:t)
        {
            mpp[i]++;
        }
        int count=mpp.size();
        int maxi=INT_MAX;
        while(right<n)
        {
            if(mpp.find(s[right])!=mpp.end())
            {
                mpp[s[right]]--;
                if(mpp[s[right]]==0)count--;
            }
           while(count==0)
            {
                if(right-left+1 < maxi)
                {
                    maxi = right-left+1;
                    start=left;
                }
            
                if(mpp.find(s[left]) != mpp.end())
                {
                    mpp[s[left]]++;
            
                    if(mpp[s[left]] == 1)
                        count++;
                }
            
                left++;
            }
            right++;
        }
        
        return maxi==INT_MAX?"":s.substr(start,maxi);
    }
};