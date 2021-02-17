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
    int max_sum = INT_MIN;
public:
    int maxSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int max_left = max(maxSum(root -> left), 0);
        int max_right = max(maxSum(root -> right), 0);

        int cur_sum = root -> val + max_left + max_right;

        max_sum = max(max_sum, cur_sum);

        return root -> val + max(max_left, max_right); 
    }

    int maxPathSum(TreeNode* root) {
        maxSum(root);

        return max_sum;
    }
};