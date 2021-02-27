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
        vector<string> result;
        queue<TreeNode*> node_queue;
        queue<string> path_queue;

        if (root != NULL) {
            node_queue.push(root);
            path_queue.push(to_string(root -> val));
        }

        while (!node_queue.empty()) {
            TreeNode *cur_node = node_queue.front(); node_queue.pop();
            string cur_path = path_queue.front(); path_queue.pop();

            if (cur_node -> left == NULL && cur_node -> right == NULL) {
                result.push_back(cur_path);
            }

            if (cur_node -> left != NULL) {
                node_queue.push(cur_node -> left);
                path_queue.push(cur_path + "->" + to_string(cur_node -> left -> val));
            }

            if (cur_node -> right != NULL) {
                node_queue.push(cur_node -> right);
                path_queue.push(cur_path + "->" + to_string(cur_node -> right -> val));
            }
        }

        return result;
    }
};