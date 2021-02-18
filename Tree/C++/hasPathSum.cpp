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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        queue<TreeNode*> node_queue;
        queue<int> vals_queue;

        node_queue.push(root);
        vals_queue.push(root -> val);

        while (!node_queue.empty()) {
            TreeNode *cur_node = node_queue.front(); node_queue.pop();
            int cur_val = vals_queue.front(); vals_queue.pop();

            if (cur_node -> left == NULL && cur_node -> right == NULL) {
                if (cur_val == targetSum) {
                    return true;
                }
            }

            if (cur_node -> left) {
                node_queue.push(cur_node -> left);
                vals_queue.push(cur_node -> left -> val + cur_val);
            }

            if (cur_node -> right) {
                node_queue.push(cur_node -> right);
                vals_queue.push(cur_node -> right -> val + cur_val);
            }
        }

        return false;
    }
};