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
    void recoverTree(TreeNode* root) {
        TreeNode*prev=nullptr;
        TreeNode*ele1=nullptr;
        TreeNode*ele2=nullptr;
        while(root)
        {
            if(!root->left)
            {
                if(prev&&prev->val>root->val)
                {
                   if(!ele1)
                   {
                    ele1=prev;
                   }
                   ele2=root;
                }
                prev=root;
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
                    root=root->left;
                }
                else
                {
                    temp->right=nullptr;
             if(prev&&prev->val>root->val)
                {
                   if(!ele1)
                   {
                    ele1=prev;
                   }
                   ele2=root;
                }
                    prev=root;
                    root=root->right;
                }
            }
        }
     swap(ele1->val,ele2->val);
    }
};