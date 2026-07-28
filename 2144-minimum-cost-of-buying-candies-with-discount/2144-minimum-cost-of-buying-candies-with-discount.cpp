class Solution {
public:
static bool cmp(int a,int b)
{
    return a>b;
}
    int minimumCost(vector<int>& cost) {
        int count=0;
        sort(cost.begin(),cost.end(),cmp);
        int total=cost.size();
        int ans=0;
        for(int i=0;i<cost.size();i++)
        {
            if(count==2)
            {
                count=0;
            }
            else
            {
            ans=ans+cost[i];
            count++;
            }
        }
        return ans;
    }
};