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
    void dfs(TreeNode *root, string path, vector<string> &result) {
        if (root == NULL) {
            return ;
        }

        path += to_string(root -> val);
        if (root -> left == NULL && root -> right == NULL) {
            result.push_back(path);
            return ;
        }

        if (root -> left) {
            dfs(root -> left, path + "->", result);
        }

        if (root -> right) {
            dfs(root -> right, path + "->", result);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<string> result;
        string path = "";
        dfs(root, path, result);

        return result;

    }
};



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<TreeNode*> node_queue;
        queue<string> val_queue;

        vector<string> result;

        if (root != nullptr) {
            node_queue.push(root);
            val_queue.push(to_string(root -> val));
        }

        while (!node_queue.empty()) {
            TreeNode *cur_node = node_queue.front(); node_queue.pop();
            string cur_val = val_queue.front(); val_queue.pop();

            if (cur_node -> left == nullptr && cur_node -> right == nullptr) {
                result.push_back(cur_val);
            }

            if (cur_node -> left != nullptr) {
                node_queue.push(cur_node -> left);
                val_queue.push(cur_val + "->" + to_string(cur_node -> left -> val));
            }

            if (cur_node -> right != nullptr) {
                node_queue.push(cur_node -> right);
                val_queue.push(cur_val + "->" + to_string(cur_node -> right -> val));
            }
        }

        return result;
    }
};