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
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(TreeNode *cur_node, int targetSum) {
        if (cur_node -> left == NULL && cur_node -> right == NULL && targetSum == 0) {
            result.push_back(path);
            return ;
        }

        if (cur_node -> left == NULL && cur_node -> right == NULL) {
            return ;
        }

        if (cur_node -> left) {
            path.push_back(cur_node -> left -> val);
            targetSum -= cur_node -> left -> val;
            backtrack(cur_node -> left, targetSum);
            targetSum += cur_node -> left -> val;
            path.pop_back();
        }

        if (cur_node -> right) {
            path.push_back(cur_node -> right -> val);
            targetSum -= cur_node -> right -> val;
            backtrack(cur_node -> right, targetSum);
            targetSum += cur_node -> right -> val;
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return result;
        }

        result.clear();
        path.clear();

        path.push_back(root -> val);

        backtrack(root, targetSum - root -> val);

        return result;

    }
};