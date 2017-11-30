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
private:
    bool isBalancedHelper(TreeNode* root, int& height) {
        int leftHeight = 0;
        int rightHeight = 0;
        bool leftBalanced = false;
        bool rightBalanced = false;

        if (root == NULL) {
            height = 0;
            return true;
        }

        leftBalanced = isBalancedHelper(root->left, leftHeight);
        rightBalanced = isBalancedHelper(root->right, rightHeight);
        height = 1 + max(leftHeight, rightHeight);

        if (!leftBalanced || !rightBalanced) {
            return false;
        } else if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return true;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height = 0;

        return isBalancedHelper(root, height);
    }
};
