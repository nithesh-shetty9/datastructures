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

TreeNode*find(TreeNode*root,int start)
{
    if(!root)return nullptr;
    if(root->val==start)return root;
    TreeNode*left=find(root->left,start);
    TreeNode*right=find(root->right,start);
    if(left)return left;
    if(right)return right;
    return nullptr;

}
    int amountOfTime(TreeNode* root, int start) {
    if(!root) return 0;
    TreeNode*target=find(root,start);
    unordered_map<TreeNode*,TreeNode*>parent;
    solve(root,parent,nullptr);
    unordered_map<TreeNode*,int>visited;
    visited[target]=1;
    queue<TreeNode*>q;
    q.push(target);
    vector<int>ans;
    int time=0;
    while(!q.empty())
    {
        bool flag=false;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode*curr=q.front();
            q.pop();
            TreeNode*curr_parent=parent[curr];
            if(curr_parent&&!visited[curr_parent])
            {
                flag=true;
                visited[curr_parent]=1;
                q.push({curr_parent});
            }
            if(curr->left&&!visited[curr->left])
            {
                flag=true;
                visited[curr->left]=1;
                q.push({curr->left});
            }
            if(curr->right&&!visited[curr->right])
            {
                flag=true;
                visited[curr->right]=1;
                q.push({curr->right});
            }

        }
         if(flag)time++;
    }
    return time;
    }
    void solve(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp,TreeNode*parent)
    {
       if(!root)return;
        mpp[root]=parent;
        solve(root->left,mpp,root);
        solve(root->right,mpp,root);
    }
};