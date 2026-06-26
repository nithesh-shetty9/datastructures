class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
       deque<int>perm(m,0);
       for(int i=0;i<m;i++)
       {
        perm[i]=i+1;
       }
       vector<int>ans;
       for(int i=0;i<queries.size();i++)
       {
        int pos = 0;

        while (perm[pos] != queries[i]) {
            pos++;
        }
        ans.push_back(pos);
        perm.erase(perm.begin()+pos);
        perm.push_front(queries[i]);
       }
       return ans;
    }
};