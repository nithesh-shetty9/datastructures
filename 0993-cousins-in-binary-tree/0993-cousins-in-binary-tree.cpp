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
    bool isCousins(TreeNode* root, int x, int y) {
        int left=0;
       int right=0;
       TreeNode*l=solve(root,x,left,0);
       TreeNode*r=solve(root,y,right,0);
       if(l==r)return false;
       if(left==right)return true;
       return false; 
    }
    TreeNode*solve(TreeNode*root,int x,int &level,int curr)
    {
       if(!root)
       {
        return nullptr;
       }
       if(root->left&&root->left->val==x)
       {
        level=curr+1;
        return root;
       }
       if(root->right&&root->right->val==x)
       {
        level=curr+1;
        return root;
       }
       TreeNode*left=solve(root->left,x,level,curr+1);
       if(left)return left;
       return solve(root->right,x,level,curr+1);
    }
};