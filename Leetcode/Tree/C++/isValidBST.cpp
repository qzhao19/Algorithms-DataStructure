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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> node_stk;
        long long min_val = (long long)INT_MIN - 1;

        TreeNode *cur_node = root;

        while (!node_stk.empty() || cur_node != NULL) {
            while (cur_node != NULL) {
                node_stk.push(cur_node);
                cur_node = cur_node -> left;
            }
            cur_node = node_stk.top(); node_stk.pop();
            if (cur_node -> val <= min_val) {
                return false;
            }
            min_val = cur_node -> val;
            cur_node = cur_node -> right;
        }
        return true;

    }
};