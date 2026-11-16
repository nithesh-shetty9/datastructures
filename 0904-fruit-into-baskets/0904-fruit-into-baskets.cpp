class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int>mpp;
       int n=fruits.size();
       int left=0;
       int right=0;
       int maxlen=0;
       int k=0;
       while(right<n)
       {
        mpp[fruits[right]]++;
        if(mpp[fruits[right]]==1)k++;
        while(k>2)
        {
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0)
            {
                k--;
            }
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
       }
       return maxlen;
    }
};