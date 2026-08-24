class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.size();
        int right=0;
        int maxi=0;
        unordered_map<int,int>mpp;
        while(right<n)
        {
            mpp[s[right]]++;
            while(left<right&&mpp[s[right]]!=1)
            {
                mpp[s[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};