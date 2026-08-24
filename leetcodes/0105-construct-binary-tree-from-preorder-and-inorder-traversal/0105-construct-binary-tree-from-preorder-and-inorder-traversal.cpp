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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        TreeNode*root=solve(preorder,0,n-1,inorder,0,n-1,mpp);
        return root;
    }
    TreeNode*solve(vector<int>& preorder,int prestart,int preend,vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mpp)
    {
        if(prestart>preend||instart>inend)
        {
            return nullptr;
        }
        TreeNode*root=new TreeNode(preorder[prestart]);
        int middle=mpp[preorder[prestart]];
        int leftnode=middle-instart;
        root->left=solve(preorder,prestart+1,prestart+leftnode,
        inorder,instart,middle-1,mpp);
        root->right=solve(preorder,prestart+leftnode+1,preend,
        inorder,middle+1,inend,mpp);
        return root;
    }
};