/**
 * Definition for a binary tree Treenode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int val, TreeTreeNode *left, TreeTreeNode *right) : val(val), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*temp=root;
        TreeNode*prev=nullptr;
        while(temp)
        {
            prev=temp;
            if(temp->val>val)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(prev)
        {
            if(prev->val>val)
            {
                prev->left=new TreeNode(val);
            }
            else
            {
                prev->right=new TreeNode(val);
            }
            return root;
        }
        return new TreeNode(val);
        
    }
};