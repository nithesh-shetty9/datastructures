/*
Longest Substring with K Uniques
Solved
Difficulty: MediumAccuracy: 34.65%Submissions: 317K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.*/
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int>hash(26,0);
        int left=0;
        int right=0;
        int count=0;
        int maxi=-1;
        while(right<s.size())
        {
             if(hash[s[right]-'a']==0)
            {
                count++;
            }
            hash[s[right]-'a']++;
            while(left<=right&&count>k)
            {
                hash[s[left]-'a']--;
                if(hash[s[left]-'a']==0)count--;
                left++;
            }
            if(k==count)
            {
                maxi=max(right-left+1,maxi);
            }
            right++;
        }
        return maxi;
    }
};