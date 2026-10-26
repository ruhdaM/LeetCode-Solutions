/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;

    int sum(TreeNode* node) {
        if (!node)
            return 0;

        int l = max(sum(node->left), 0);
        int r = max(sum(node->right), 0);
        ans = max(ans, node->val + l + r);

        return node->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        sum(root);
        return ans;
    }
};