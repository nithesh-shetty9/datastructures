class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
    void merge(vector<int>& nums,int low,int high)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            merge(nums,low,mid);
            merge(nums,mid+1,high);
            mergeit(nums,low,mid,high);
        }
    }
        void mergeit(vector<int>&nums,int low,int mid,int high)
        {
            vector<int>temp;
            int left=low;
            int right=mid+1;
            while(left<=mid&&right<=high)
            {
                if(nums[left]>=nums[right])
                {
                    temp.push_back(nums[right]);
                    right++;
                }
                else
                {
                    temp.push_back(nums[left]);
                    left++;
                }
            }
            while(left<=mid)
            {
                temp.push_back(nums[left]);
                left++;
            }
             while(right<=high)
            {
                temp.push_back(nums[right]);
                right++;
            }
            for(int i=low;i<=high;i++)
            {
                nums[i]=temp[i-low];
            }
        }
};