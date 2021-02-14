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
public:
    bool helper(TreeNode *left_tree, TreeNode *right_tree) {
        if (left_tree == NULL && right_tree == NULL) {
            return true;
        }

        if (left_tree == NULL || right_tree == NULL) {
            return false;
        }

        if (left_tree -> val != right_tree -> val) {
            return false;
        }

        return helper(left_tree -> left, right_tree -> right) && helper(left_tree -> right, right_tree -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        return helper(root -> left, root -> right);
    }
};