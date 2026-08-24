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
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                root=q.front();
                q.pop();
                if(root->left)
                {
                    q.push(root->left);
                    mpp[root->left]=root;
                }
                if(root->right)
                {
                    q.push(root->right);
                    mpp[root->right]=root;
                }
            }  
        }
        vector<int>ans;
        queue<TreeNode*>track;
        track.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(k--)
        {
            int n=track.size();
            for(int i=0;i<n;i++)
            {
                root=track.front();
                track.pop();
                if(root->left&&!visited[root->left])
                {
                    visited[root->left]=true;
                    track.push(root->left);
                }
                if(root->right&&!visited[root->right])
                {
                    visited[root->right]=true;
                    track.push(root->right);
                }
                if(mpp[root]&&!visited[mpp[root]])
                {
                    visited[mpp[root]]=true;
                    track.push(mpp[root]);
                }
            }
        }
        while(!track.empty())
        {
            ans.push_back(track.front()->val);
            track.pop();
        }
        return ans;

    }
};