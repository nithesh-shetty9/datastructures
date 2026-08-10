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
         vector<vector<int>>ans;
         map<int,map<int,multiset<int>>>mpp;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int row=q.front().second.first;
                int col=q.front().second.second;
                root=q.front().first;
                q.pop();
                mpp[col][row].insert(root->val);
                if(root->left)q.push({root->left,{row+1,col-1}});
                if(root->right)q.push({root->right,{row+1,col+1}});
            }
            
        }
        for(auto j:mpp)
        {
             vector<int> temp;
            for(auto it:j.second)
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