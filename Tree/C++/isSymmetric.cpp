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
public:
    bool dfs(TreeNode *left_node, TreeNode *right_node) {
        if (left_node == nullptr && right_node == nullptr) {
            return true;
        }

        if (left_node == nullptr || right_node == nullptr) {
            return false;
        }

        if (left_node -> val != right_node -> val) {
            return false;
        }

        return dfs(left_node -> left, right_node -> right) && dfs(left_node -> right, right_node -> left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return dfs(root -> left, root -> right);

    }
};



class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> node_queue1;
        queue<TreeNode*> node_queue2;

        if (root != nullptr) {
            node_queue1.push(root -> left);
            node_queue2.push(root -> right);
        }

        while (!node_queue1.empty() && !node_queue2.empty()) {
            TreeNode *left_node = node_queue1.front(); node_queue1.pop();
            TreeNode *right_node = node_queue2.front(); node_queue2.pop();

            if (left_node == nullptr && right_node == nullptr) {
                continue;
            }

            if (left_node == nullptr || right_node == nullptr) {
                return false;
            }

            if (left_node -> val != right_node -> val) {
                return false;
            }

            node_queue1.push(left_node -> left);
            node_queue1.push(left_node -> right);

            node_queue2.push(right_node -> right);
            node_queue2.push(right_node -> left);
        }

        return true;
    }
};