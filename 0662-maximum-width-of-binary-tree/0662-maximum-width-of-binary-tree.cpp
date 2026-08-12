/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        long long width=0;
        q.push({root,0});
        while(!q.empty())
        {
            long long n=q.size();
            long long mini=q.front().second;
            long long first,last;
            for(long long i=0;i<n;i++)
            {
                long long index=q.front().second-mini;
                root=q.front().first;
                q.pop();
                if(i==0)first=index;
                if(i==n-1)last=index;
                if(root->left)q.push({root->left,index*2+1});
                if(root->right)q.push({root->right,index*2+2});
            }
            width=max(width,last-first+1);
        }
        return width;
    }
};