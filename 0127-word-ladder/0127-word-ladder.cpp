class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>mpp;
        for(auto i:wordList)
        {
            mpp.insert(i);
        }
        if(!mpp.count(endWord))return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            int size=q.size();
            for(int k=0;k<size;k++)
            {
            string word=q.front().first;
            auto it=q.front().second;
            q.pop();
            if(word==endWord)
            {
                return it;
            }
            for(int i=0;i<word.size();i++)
            {
            for(int j=0;j<26;j++)
            {
                string temp=word;
                temp[i]='a'+j;
                if(mpp.count(temp))
                {
                    mpp.erase(temp);
                    q.push({temp,it+1});
                }     
            }
            }
            }
        }
        return 0;
    }
};