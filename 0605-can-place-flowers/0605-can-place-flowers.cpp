class Solution {
public:
    bool canPlaceFlowers(vector<int>&nums, int n) {
        int size=nums.size();
          if(n==0)return true;
        for(int i=0;i<size;i++)
        {
            if(nums.size()==1)
            {
                if(nums[i]==0)
                {
                n--;
                nums[i]=1;
                }
            }
            else if(i==0&&nums[i]==0&&nums[i+1]==0)
            {
                n--;
                nums[i]=1;
            }
            else if(i==size-1&&nums[i-1]==0&&nums[i]==0)
            {
                n--;
                nums[i]=1;
            }
            else if(i>0&&i<size-1&&nums[i]==0&&nums[i-1]==0&&nums[i+1]==0)
            {
                n--;
                nums[i]=1;
            }
            
           if(n==0)
           {
            return true;
           }
        }
        return false;
    }
};