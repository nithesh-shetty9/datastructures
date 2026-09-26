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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root)
        {
            if(!root->left)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
               TreeNode*temp=root->left;
                while(temp->right&&temp->right!=root)
                {
                    temp=temp->right;
                }
                if(!temp->right)
                {
                    temp->right=root;
                    ans.push_back(root->val);
                    root=root->left;
                }
                else
                {
                    temp->right=nullptr;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};