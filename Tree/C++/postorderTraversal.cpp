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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stk;

        if (root != NULL) {
            node_stk.push(root);
        }

        while (!node_stk.empty()) {
            TreeNode *cur_node = node_stk.top();
            if (cur_node != NULL) {
                node_stk.pop();
                node_stk.push(cur_node);
                node_stk.push(nullptr);
                if (cur_node -> right != NULL) {
                    node_stk.push(cur_node -> right);
                }
                if (cur_node -> left != NULL) {
                    node_stk.push(cur_node -> left);
                }
            }
            else {
                node_stk.pop();
                cur_node = node_stk.top();
                node_stk.pop();
                result.push_back(cur_node -> val);
            }
        }

        return result;
    }
};