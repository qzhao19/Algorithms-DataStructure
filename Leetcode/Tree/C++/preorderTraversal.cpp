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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stk;

        if (root != NULL) {
            node_stk.push(root);
        }

        while (!node_stk.empty()) {
            TreeNode *cur_node = node_stk.top();
            if (cur_node != NULL) {
                node_stk.pop();
                if (cur_node -> right != NULL) {
                    node_stk.push(cur_node -> right);
                }
                if (cur_node -> left != NULL) {
                    node_stk.push(cur_node -> left);
                }
                node_stk.push(cur_node);
                node_stk.push(nullptr);
            }
            else {
                // pop nullptr node
                node_stk.pop();
                cur_node = node_stk.top();
                node_stk.pop();
                result.push_back(cur_node -> val);
            }
        }

        return result;
    }
};

class Solution {
private:
    vector<int> result;
public:
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return ;
        }

        result.push_back(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        dfs(root);

        return result;
    }
};