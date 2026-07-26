class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int left=0;
    int right=0;
    int maxi=0;
    int n=fruits.size();
    unordered_map<int,int>mpp;
    int baskets=0;
    while(right<n)
    {
        if(mpp[fruits[right]]==0)baskets++;
        mpp[fruits[right]]++;
        while(left<right&&baskets>2)
        {
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0)
            {
                baskets--;
            }
            left++;
        }
        maxi=max(maxi,right-left+1);
        right++;
    }    
    return maxi;
        
    }
};