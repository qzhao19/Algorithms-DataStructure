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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> node_queue;
        int level = 0;

        if (root) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            int q_size = node_queue.size();
            vector<int> tmp;
            result.push_back(tmp);

            while (q_size--) {
                TreeNode *cur_node = node_queue.front(); node_queue.pop();
                result[level].push_back(cur_node -> val);
                if (cur_node -> left) {
                    node_queue.push(cur_node -> left);
                }

                if (cur_node -> right) {
                    node_queue.push(cur_node -> right);
                }
            }
            if (level % 2 != 0) {
                reverse(result[level].begin(), result[level].end());
            }
            level++;
        }

        return result;
    }
};