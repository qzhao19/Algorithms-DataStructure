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
    void preorderTraversal(TreeNode *root, vector<int> &node_vec) {

        if (root == nullptr) {
            return ;
        }
        node_vec.push_back(root -> val);
        preorderTraversal(root -> left, node_vec);
        preorderTraversal(root -> right, node_vec);

    }

    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }

        vector<int> node_vec;
        preorderTraversal(root, node_vec);
        int n = node_vec.size();

        for (int i = 1; i < n; i++) {
            root -> left = nullptr;
            root -> right = new TreeNode(node_vec[i]);
            root = root -> right;
        }
        
    }
};