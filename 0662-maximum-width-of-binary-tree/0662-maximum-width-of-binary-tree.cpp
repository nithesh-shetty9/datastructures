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
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            long long first,last;
            long long mini=q.front().second;
            for(int i=0;i<n;i++)
            {
                root=q.front().first;
                int idx=q.front().second-mini;
                q.pop();
                if(i==0)first=idx;
                if(i==n-1)last=idx;
                if(root->left)q.push({root->left,idx*2LL+1});
                if(root->right)q.push({root->right,idx*2LL+2});
            }
            maxi=max(maxi,first+last+1);
        }
        return maxi;
    }
};