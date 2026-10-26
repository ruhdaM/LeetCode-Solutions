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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        preorder(root, 1, ans);
        return ans;
    }

    void preorder(TreeNode* root, int depth, int& ans) {
        if (!root)
            return;

        ans = max(ans, depth);
        preorder(root->left, depth + 1, ans);
        preorder(root->right, depth + 1, ans);
    }
};