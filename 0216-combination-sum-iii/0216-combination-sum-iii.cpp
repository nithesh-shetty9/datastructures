class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n)return {};
        vector<int>nums;
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }
        vector<vector<int>>res;
        vector<int>temp;
        int sum=0;
        find(res,nums,n,k,temp,0,sum);
        return res;
    }
    void find(vector<vector<int>>&res,vector<int>nums,int n,int k,vector<int>temp,int index,int sum)
    {
        if(temp.size()==k)
        {
            if(n==sum)
            {
            res.push_back(temp);
            }return;
        }
        if(sum>n)return;
         if(index>=nums.size())return;
        temp.push_back(nums[index]);
        find(res,nums,n,k,temp,index+1,sum+nums[index]);
        temp.pop_back();
        find(res,nums,n,k,temp,index+1,sum);



    }
};