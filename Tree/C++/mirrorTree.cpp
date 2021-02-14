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
    TreeNode* helper(TreeNode *root){

        if (root) {

            swap(root->left, root->right);
            root->left = helper(root->left);
            root->right = helper(root->right);
        }

        return root;
    }
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) {
            return nullptr;
        }

        return helper(root);
    }
};