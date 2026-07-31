class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int maxi=0;
        int n=s.size();
        for(int size=minSize;size<=maxSize;size++)
        {
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
            while(maxLetters<0||(right-left+1)>size)
            {
                hash[s[left]-'a']--;
                if(hash[s[left]-'a']==0)maxLetters++;
                left++;
            }
            if(maxLetters>=0&&(right-left+1)==size)
            {
                string temp=s.substr(left,right-left+1);
                cout<<temp<<endl;
                mpp[temp]++;
                maxi=max(maxi,mpp[temp]);
            }
            right++;
        }
        }
        return maxi;
    }
};