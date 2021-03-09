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
    vector<int> path;
    vector<vector<int>> result;
public:
    void backtrack(TreeNode *root, int targetSum) {

        if (root -> left == nullptr && root -> right == nullptr && targetSum == 0) {
            result.push_back(path);
            return ;
        }

        if (root -> left != nullptr) {
            path.push_back(root -> left -> val);
            targetSum -= root -> left -> val;
            backtrack(root -> left, targetSum);
            targetSum += root -> left -> val;
            path.pop_back();
        }

        if (root -> right != nullptr) {
            path.push_back(root -> right -> val);
            targetSum -= root -> right -> val;
            backtrack(root -> right, targetSum);
            targetSum += root -> right -> val;
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }

        path.push_back(root -> val);

        backtrack(root, targetSum - root -> val);

        return result;

    }
};