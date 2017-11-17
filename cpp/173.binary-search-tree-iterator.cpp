/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans = 0;
        TreeNode *ptr = NULL;

        if (st.empty()) {
            return -1;
        }

        ptr = st.top();
        st.pop();
        ans = ptr->val;

        ptr = ptr->right;
        while (ptr != NULL) {
            st.push(ptr);
            ptr = ptr->left;
        }

        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
