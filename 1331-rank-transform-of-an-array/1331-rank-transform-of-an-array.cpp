class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]].push_back(i);
            
        }
        int rank=1;
        for(auto it:mpp)
        {
            for(auto j:it.second)
            {
                arr[j]=rank;
            }
            rank++;
        }
        return arr;   
    }
};