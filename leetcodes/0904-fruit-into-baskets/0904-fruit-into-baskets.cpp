class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count=0;
        int maxi=0;
        int left=0;
        int right=0;
        unordered_map<int,int>mpp;
        int n=fruits.size();
        while(right<n)
        {
            mpp[fruits[right]]++;
            if(mpp[fruits[right]]==1)count++;
            while(left<=right&&count>2)
            {
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0)count--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};