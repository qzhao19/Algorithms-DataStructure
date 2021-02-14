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

    TreeNode *buildTree(vector<int> &preorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right) {
            return nullptr;
        }

        int root_val = preorder[pre_left];
        TreeNode *root = new TreeNode(root_val);
        int pivot_idx = hash_map[root_val];

        root -> left = buildTree(preorder, pre_left + 1, pivot_idx - in_left + pre_left, in_left, pivot_idx - 1);
        root -> right = buildTree(preorder, pivot_idx - in_left + pre_left + 1, pre_right, pivot_idx + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_length = preorder.size(), in_length = inorder.size();

        if (pre_length != in_length) {
            return nullptr;
        }

        for (int i = 0; i < in_length; i++) {
            hash_map[inorder[i]] = i;
        }

        return buildTree(preorder, 0, pre_length - 1, 0, in_length - 1);

    }
};