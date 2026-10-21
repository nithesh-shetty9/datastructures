class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i:weights)
        {
            high+=i;
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int ships=1;
            int cargo=0;
            for(int i=0;i<weights.size();i++)
            {
                if(cargo+weights[i]>mid)
                {
                    cargo=weights[i];
                    ships++;
                }
                else
                {
                    cargo=cargo+weights[i];
                }
            }
            if(ships<=days)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;

    }
};