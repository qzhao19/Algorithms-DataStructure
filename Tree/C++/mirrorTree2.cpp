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
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> node_queue;
        node_queue.push(root);

        if (root == NULL) {
            return nullptr;
        }
        
        while (!node_queue.empty()) {
            TreeNode *cur_node = node_queue.front(); node_queue.pop();
            swap(cur_node -> left, cur_node -> right);

            if (cur_node -> left != NULL) {
                node_queue.push(cur_node -> left);
            }

            if(cur_node -> right != NULL) {
                node_queue.push(cur_node -> right);
            }
        }

        return root;
    }
};