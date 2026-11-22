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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        TreeNode*root=new TreeNode(preorder[idx]);
        idx++;
         solve(preorder,idx,root);
         return root;
    }
    void solve(vector<int>&preorder,int &idx,TreeNode*curr)
    {
        if(idx==preorder.size())return;
        TreeNode*root=curr;
        TreeNode*prev=nullptr;
      while(root)
      {
        prev=root;
        if(root->val>preorder[idx])
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
      }
      if(prev)
      {
        if(preorder[idx]>prev->val)
        {
            prev->right=new TreeNode(preorder[idx]);
        }
        else
        {
            prev->left=new TreeNode(preorder[idx]);
        }
      }
      idx++;
       solve(preorder,idx,curr);
    }
};