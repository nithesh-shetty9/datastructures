class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }

    int solve(TreeNode* root, int mini, int maxi) {
        if (!root)
            return maxi - mini;

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);

        return max(
            solve(root->left, mini, maxi),
            solve(root->right, mini, maxi)
        );
    }
};