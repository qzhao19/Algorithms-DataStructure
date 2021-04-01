/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> hash_map;
public:
    TreeNode *dfs(vector<int> &preorder, int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right) {
            return nullptr;
        }

        int root_val = preorder[pre_left];
        TreeNode *root = new TreeNode(root_val);
        int pivot = hash_map[root_val];

        root -> left = dfs(preorder, pre_left + 1, pivot - in_left + pre_left, in_left, pivot - 1);
        root -> right = dfs(preorder, pivot - in_left + pre_left + 1, pre_right, pivot + 1, in_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) {
            return nullptr;
        }

        int pre_length = preorder.size(), in_length = inorder.size();

        for (int i = 0; i < in_length; i++) {
            hash_map[inorder[i]] = i;
        }

        return dfs(preorder, 0, pre_length - 1, 0, in_length - 1);
    }
};