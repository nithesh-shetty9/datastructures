/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       queue<pair<TreeNode*,pair<int,int>>>q;
       q.push({root,{0,0}});
       map<int,map<int,multiset<int>>>mpp;
       while(!q.empty())
       {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            root=q.front().first;
            int col=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mpp[col][level].insert(root->val);
            if(root->left)q.push({root->left,{col-1,level+1}});
             if(root->right)q.push({root->right,{col+1,level+1}});
        }
       } vector<vector<int>>ans;
       for(auto ele:mpp)
       {
        vector<int>temp;
        for(auto it:ele.second)
        {
            for(auto k:it.second)
            {
                temp.push_back(k);
            }
       }
         ans.push_back(temp);
       }
       return ans;
    }
};