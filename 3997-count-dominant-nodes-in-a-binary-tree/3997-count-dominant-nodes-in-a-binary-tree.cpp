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
    int res=0;
public:
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return res;
    }
    int  solve(TreeNode*root)
    {
        if(!root)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        if(root->val>=max(left,right))
        {
            res++;
        }
       return max(root->val, max(left, right));;
    }
};