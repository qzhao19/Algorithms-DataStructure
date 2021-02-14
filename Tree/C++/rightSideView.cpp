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
    vector<int> result;
public:
    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            return ;
        }

        if (result.size() == depth) {
            result.push_back(root -> val);
        }

        depth++;
        dfs(root -> right, depth);
        dfs(root -> left, depth);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        dfs(root, 0);

        return result;
    }
};