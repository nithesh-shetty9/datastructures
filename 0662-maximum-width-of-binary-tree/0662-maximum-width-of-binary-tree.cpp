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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            long long mini=q.front().second;
            int n=q.size();
            long long first=LLONG_MAX;
            long long last=0;
            for(int i=0;i<n;i++)
            {
                root=q.front().first;
                long long curr=q.front().second-mini;
                q.pop();
                first=min(first,curr);
                last=max(last,curr);
                if(root->left)q.push({root->left,2*1LL*curr+1});
                if(root->right)q.push({root->right,2*1LL*curr+2});
            }
            maxi=max(maxi,last-first+1);
        }
        return (int)maxi;
    }
};