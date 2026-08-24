class Solution {
public:
    int candy(vector<int>& ratings) {
        int total=ratings.size();
        int ans=0;
        vector<int>arr(total,1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                arr[i]=arr[i-1]+1;
            }
        }
        for(int i=total-1;i>=0;i--)
        {
            if(i!=total-1&&ratings[i]>ratings[i+1])
            {
                if(arr[i]<=arr[i+1])
                {
                    arr[i]=arr[i+1]+1;
                }
            }
            ans+=arr[i];
        }
        return ans;
    }
};