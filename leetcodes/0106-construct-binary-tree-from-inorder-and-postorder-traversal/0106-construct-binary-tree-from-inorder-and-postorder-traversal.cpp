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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        int n=postorder.size();
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode*root=solve(postorder,0,n-1,inorder,0,n-1,mpp);
        return root;
    }
    TreeNode*solve(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&mpp){
        if(postend<poststart)return nullptr;
        TreeNode*root=new TreeNode(postorder[postend]);
        int middle=mpp[postorder[postend]];
        int rightnodes=inend-middle;
        root->right=solve(postorder,postend-rightnodes,postend-1,inorder,
        middle+1,inend,mpp);
        root->left=solve(postorder,poststart,postend-rightnodes-1,inorder,
        instart,middle-1,mpp);
        return root;
    }
};