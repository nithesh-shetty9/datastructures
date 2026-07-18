class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st{nums.begin(),nums.end()};
        int count=0;
        int maxi=0;
        for(auto it:st)
        {
            int temp=it;
            if(!st.count(temp-1))
            {
                count=1;
                while(st.count(temp+1))
                {
                    count++;
                    temp+=1;
                }
            }
            maxi=max(count,maxi);
            count=0;
        }
        return maxi;
    }
};