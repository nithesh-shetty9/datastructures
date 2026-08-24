class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        vector<vector<int>>bucket(s.size()+1);
        for(auto it:mpp)
        {
            bucket[it.second].push_back(it.first);
        }
       
        string res="";
        for(int i=s.size();i>=1;i--)
        {
            for(auto it:bucket[i])
            {
                res.append(i,it);
            }
        }
        return res;
    }
};