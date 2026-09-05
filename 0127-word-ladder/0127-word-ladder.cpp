class Solution {
public:
    int ladderLength(string s, string e, vector<string>& words) {
        unordered_set<string>track{words.begin(),words.end()};
        queue<pair<string,int>>q;
        q.push({s,1});
        while(!q.empty())
        {
            int size=q.size();
            int level=q.front().second;
            for(int i=0;i<size;i++)
            {
                string curr=q.front().first;
                q.pop();
                for(int j=0;j<curr.size();j++)
                {
                    string currword=curr;
                    for(int k=0;k<26;k++)
                    {
                        currword[j]='a'+k;
                        if(track.count(currword))
                        {
                            if(currword==e)return level+1;
                            track.erase(currword);
                            q.push({currword,level+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};