/**
 * Definition for a binary tree TreeNode  .
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNod *left;
 *     TreeTreeNod *right;
 *     TreeTreeNod(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode *,TreeNode*>mpp;
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
        queue<TreeNode*>final;
        unordered_map<TreeNode*,bool>visited;
        visited[target] = true;
        final.push(target);
        while(k--)
        {
            int n=final.size();
            for(int i=0;i<n;i++)
            {
            root=final.front();
            final.pop();
            if(root->left&&!visited[root->left])
            {
                final.push(root->left);
                visited[root->left]=true;
            }
            if(root->right&&!visited[root->right])
            {
                final.push(root->right);
                visited[root->right]=true;
            }
            if(mpp[root]&&!visited[mpp[root]])
            {
                final.push(mpp[root]);
                visited[mpp[root]]=true;
            }
            }
        }
        vector<int>res;
        while(!final.empty())
        {
            res.push_back(final.front()->val);
            final.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
   
};