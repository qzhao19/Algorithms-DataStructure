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
private:
    vector<int> result;
public:
    void dfs(TreeNode* root, int depth) {
        if (root == NULL) {
            return ;
        }

        if (result.size() == depth) {
            result.push_back(root -> val);
        }

        depth++;
        dfs(root -> right, depth);
        dfs(root -> left, depth);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        dfs(root, 0);

        return result;
    }
};



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> node_queue;
        vector<int> result;

        if (root != nullptr) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            int q_size = node_queue.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode *cur_node = node_queue.front(); node_queue.pop();

                if (i == q_size - 1) {
                    result.push_back(cur_node -> val);
                }

                if (cur_node -> left != nullptr) {
                    node_queue.push(cur_node -> left);
                }

                if (cur_node -> right != nullptr) {
                    node_queue.push(cur_node -> right);
                }
            }
        }

        return result;

    }
};