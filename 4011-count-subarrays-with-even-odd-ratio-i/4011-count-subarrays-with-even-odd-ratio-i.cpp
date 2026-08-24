class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int sum=0;
        double target= 1.0 * a / b;
        for(int i=0;i<n;i++)
        {
            int odd=0;
            int even=0;
            for(int j=i;j<n;j++)
            {
                double temp=0;
                if(nums[j]%2!=0)odd++;
                if(nums[j]%2==0)even++;
                if(odd>0){
                    temp=1.0*even/odd;
                    if(temp<=target)
                    {
                        sum++;
                    }
                }
            }
        }
        return sum;
    }
};