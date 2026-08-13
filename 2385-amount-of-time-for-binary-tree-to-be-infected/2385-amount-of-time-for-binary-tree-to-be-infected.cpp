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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    mpp[temp->left]=temp;
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    mpp[temp->right]=temp;
                }
            }
        }
        TreeNode*target=find(root,start);
        queue<TreeNode*>track;
        track.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int ans=0;
        while(!track.empty())
        {
            bool flag=false;
            int n=track.size();
            for(int i=0;i<n;i++)
            {
                root=track.front();
                track.pop();
                if(root->left&&!visited[root->left])
                {
                    flag=true;
                    visited[root->left]=true;
                    track.push(root->left);
                }
                if(root->right&&!visited[root->right])
                {
                    flag=true;
                    visited[root->right]=true;
                    track.push(root->right);
                }
                if(mpp[root]&&!visited[mpp[root]])
                {
                     flag=true;
                    visited[mpp[root]]=true;
                    track.push(mpp[root]);
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
    TreeNode*find(TreeNode*root,int target)
    {
        if(!root||root->val==target)
        {
            return root;
        }
        TreeNode*left=find(root->left,target);
        if(left)return left;
        TreeNode*right=find(root->right,target);
        return right;
    }
};