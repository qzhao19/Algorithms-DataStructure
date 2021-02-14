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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        queue<TreeNode*> node_queue;
        node_queue.push(root -> left);
        node_queue.push(root -> right);

        
        while (!node_queue.empty()){
            TreeNode *node1 = node_queue.front(); node_queue.pop();
            TreeNode *node2 = node_queue.front(); node_queue.pop();

            if (node1 == NULL && node2 == NULL) continue;
            
            if (node1 == NULL || node2 == NULL) return false;

            if (node1 -> val != node2 -> val) return false;

            node_queue.push(node1 -> left);
            node_queue.push(node2 -> right);

            node_queue.push(node1 -> right);
            node_queue.push(node2 -> left);
            
        }

        return true;
    }
};