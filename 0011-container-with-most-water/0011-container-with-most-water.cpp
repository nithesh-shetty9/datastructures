class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        long long ans=0;
        while(high>=0&&low<height.size())
        {
            int mini=min(height[low],height[high]);
            long long res=(mini)*1LL*(high-low);
            ans=max(ans,res);
            if(height[low]<height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return ans;
    }
};