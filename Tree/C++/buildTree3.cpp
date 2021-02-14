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
    unordered_map<int, int> hash_map;
public:

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder, int in_left, int in_right, int post_left, int post_right) {

        if (in_left > in_right || post_left > post_right) {
            return nullptr;
        }

        int root_val = postorder[post_right];
        TreeNode *root = new TreeNode(root_val);
        int pivot_idx = hash_map[root_val];

        root -> left = buildTree(inorder, postorder, in_left, pivot_idx - 1, post_left, pivot_idx - 1 - in_left + post_left);
        root -> right = buildTree(inorder, postorder, pivot_idx + 1, in_right, pivot_idx - in_left + post_left, post_right - 1);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_length = inorder.size(), post_length = postorder.size();

        if (in_length != post_length) {
            return nullptr;
        }

        for (int i = 0; i < in_length; i++) {
            hash_map[inorder[i]] = i;
        }

        return buildTree(inorder, postorder, 0, in_length - 1, 0, post_length - 1);

    }
};