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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> node_queue;
        int level = 0;

        if (root != NULL) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            int q_size = node_queue.size();
            vector<int> tmp;
            result.push_back(tmp);
            while (q_size--) {
                TreeNode *cur_node = node_queue.front(); 
                result[level].push_back(cur_node -> val);
                node_queue.pop();

                if (cur_node -> left != NULL) {
                    node_queue.push(cur_node -> left);
                }

                if (cur_node -> right != NULL) {
                    node_queue.push(cur_node -> right);
                }
            }
            level++;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};