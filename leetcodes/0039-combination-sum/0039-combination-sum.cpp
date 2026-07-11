class Solution {
    void find(vector<int>candidates,int k,int sum,int index,vector<vector<int>>&ans,vector<int>temp)
    {
        if(sum>k)return;
        if(sum==k)
        {
            ans.push_back(temp);
            return;
        }
        if(index>=candidates.size())return;
        temp.push_back(candidates[index]);
        find(candidates,k,sum+candidates[index],index,ans,temp);
        temp.pop_back();
         find(candidates,k,sum,index+1,ans,temp);
    }
    //rememer here excelude first element use it correctluy dont add to sum
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>ans;
            vector<int>temp;
        find(candidates,target,0,0,ans,temp);
            return ans;
    }
};