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
        queue<TreeNode*> node_queue;
        node_queue.push(root);

        if (root == NULL){
            return 0;
        }
        int counter = 0;
        while(!node_queue.empty()){
            int size = node_queue.size();
            while(size--){
                TreeNode *cur_node = node_queue.front();
                if (cur_node -> left != NULL){
                    node_queue.push(cur_node -> left);
                }
                if (cur_node -> right != NULL){
                    node_queue.push(cur_node -> right);
                }
                node_queue.pop();
            }
        counter++;
        
        }
        return counter;

    }
};