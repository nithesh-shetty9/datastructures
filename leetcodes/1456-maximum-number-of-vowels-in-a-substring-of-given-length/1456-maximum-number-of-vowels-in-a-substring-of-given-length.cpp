class Solution {
public:
    int maxVowels(string s, int k) {
       vector<char>hash(26,0);
       int n=s.size();
       int right=0;
       int left=0;
       int vowel=0;
       int maxi=0;
       while(right<n)
       {
        hash[s[right]-'a']++;
        if(s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='u'||s[right]=='o')
        {
            vowel++;
        }
        if(right-left+1>k)
        {
            hash[s[left]-'a']--;
              if(s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='u'||s[left]=='o')
              {
                vowel--;
              }
            left++;
        }
        if(right-left+1==k)
        {
            maxi=max(maxi,vowel);
        }
        right++;
       } 
       return maxi;
    }
};