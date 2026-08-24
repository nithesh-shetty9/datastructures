class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int maxi=0;
        int n=s.size();
        //considder only imsubrting as consider a example of pla place ths substring pla is only chcoice to get maxsubrting of place right so minsubstring is enoug
        unordered_map<string,int>mpp;
         vector<char>hash(26,0);
        int left=0;
        int right=0;
        while(right<n)
        {
            hash[s[right]-'a']++;
            if(hash[s[right]-'a']==1)
            {
                maxLetters--;
            }
            while(maxLetters<0||(right-left+1)>minSize)
            {
                hash[s[left]-'a']--;
                if(hash[s[left]-'a']==0)maxLetters++;
                left++;
            }
            if(maxLetters>=0&&(right-left+1)==minSize)
            {
                string temp=s.substr(left,right-left+1);
                mpp[temp]++;
                maxi=max(maxi,mpp[temp]);
            }
            right++;
        }
        return maxi;
    }
};