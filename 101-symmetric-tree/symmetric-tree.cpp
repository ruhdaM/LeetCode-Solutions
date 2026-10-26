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
    bool isSymmetric(TreeNode* root) {
        vector<int> a, b;
        pre(root->left, a);
        mirror(root->right, b);

        return a == b;
    }

    void pre(TreeNode* node, vector<int>& a) {
        if (!node) {
            a.push_back(INT_MIN);
            return;
        }

        a.push_back(node->val);
        pre(node->left, a);
        pre(node->right, a);
    }

    void mirror(TreeNode* node, vector<int>& b) {
        if (!node) {
            b.push_back(INT_MIN);
            return;
        }

        b.push_back(node->val);
        mirror(node->right, b);
        mirror(node->left, b);
    }
};