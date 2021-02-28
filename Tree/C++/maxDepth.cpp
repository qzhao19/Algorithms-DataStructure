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
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        return max(maxDepth(root -> left), (maxDepth(root -> right))) + 1;
    }
};



class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> node_queue;
        int depth = 0;

        if (root != nullptr) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            int q_size = node_queue.size();

            while (q_size--) {
                TreeNode *cur_node = node_queue.front(); node_queue.pop();
                if (cur_node -> left != nullptr) {
                    node_queue.push(cur_node -> left);
                }

                if (cur_node -> right != nullptr) {
                    node_queue.push(cur_node -> right);
                }
            }

            depth++;
        }

        return depth;
    }
};