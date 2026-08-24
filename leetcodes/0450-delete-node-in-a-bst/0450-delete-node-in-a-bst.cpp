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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val==key)
        {
            return solve(root);
        }
        TreeNode*d=root;
        while(root)
        {
            if(root->val>key)
            {
                if(root->left&&root->left->val==key)
                {
                    root->left=solve(root->left);
                    break;
                }
                else
                {
                    root=root->left;
                }
            }
            else
            {
                if(root->right&&root->right->val==key)
                {
                    root->right=solve(root->right);
                    break;
                }
                else
                {
                    root=root->right;
                }
            }
        }
        return d;
    }
    TreeNode*solve(TreeNode*root)
    {
        if(!root->left)return root->right;
        if(!root->right)return root->left;
        TreeNode*right=root->right;
        TreeNode*last=find(root->left);
        last->right=right;
        return root->left;
    }
    TreeNode*find(TreeNode*root)
    {
        while(root->right)
        {
            root=root->right;
        }
        return root;
    }
};