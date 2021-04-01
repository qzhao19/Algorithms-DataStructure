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
    TreeNode *dfs(vector<int> &postorder, int in_left, int in_right, int post_left, int post_right) {
        if (in_left > in_right || post_left > post_right) {
            return nullptr;
        }

        int root_val = postorder[post_right];
        TreeNode *root = new TreeNode(root_val);
        int pivot = hash_map[root_val];

        root -> left = dfs(postorder, in_left, pivot - 1, post_left, pivot - 1 - in_left + post_left);
        root -> right = dfs(postorder, pivot + 1, in_right, pivot - in_left + post_left, post_right - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }

        int in_length = inorder.size(), post_length = postorder.size();

        for (int i = 0; i < in_length; i++) {
            hash_map[inorder[i]] = i;
        }

        return dfs(postorder, 0, in_length - 1, 0, post_length - 1);
    }
};