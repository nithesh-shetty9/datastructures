/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //find the loccaion of target element;
    //use map to store parent element of eveynode;
    if(!root) return {};
    if(k==0)return {target->val};
    unordered_map<TreeNode*,TreeNode*>parent;
    solve(root,parent,nullptr);
    unordered_map<TreeNode*,int>visited;
    visited[target]=1;
    queue<TreeNode*>q;
    q.push(target);
    vector<int>ans;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode*curr=q.front();
            q.pop();
            if(k==0)ans.push_back(curr->val);
            TreeNode*curr_parent=parent[curr];
            if(curr_parent&&!visited[curr_parent])
            {
                visited[curr_parent]=1;
                q.push({curr_parent});
            }
            if(curr->left&&!visited[curr->left])
            {
                visited[curr->left]=1;
                q.push({curr->left});
            }
            if(curr->right&&!visited[curr->right])
            {
                visited[curr->right]=1;
                q.push({curr->right});
            }

        }
        if(k==0)break;
        k--;
    }
    return ans;

    }
    void solve(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode*parent)
    {
       if(!root)return;
        mpp[root]=parent;
        solve(root->left,mpp,root);
        solve(root->right,mpp,root);
    }
};