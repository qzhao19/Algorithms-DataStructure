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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return nullptr;
        }

        swap(root -> left, root -> right);

        if (root -> left != NULL) {
            invertTree(root -> left);
        }

        if (root -> right != NULL) {
            invertTree(root -> right);
        }

        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> node_queue;

        if (root != NULL) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            TreeNode *cur_node = node_queue.front(); node_queue.pop();

            swap(cur_node -> left, cur_node -> right);

            if (cur_node -> left != NULL) {
                node_queue.push(cur_node -> left);
            }

            if (cur_node -> right != NULL) {
                node_queue.push(cur_node -> right);
            }
        }

        return root;
    }
};