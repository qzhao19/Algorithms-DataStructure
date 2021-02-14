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

    TreeNode* helper(vector<int> preorder, vector<int> inorder, int root_idx, int left, int right){

        if (left > right) return nullptr;
        // define root node
        int root_val = preorder[root_idx];
        TreeNode *root = new TreeNode(root_val);

        // define move and mid
        int move = 0, mid = left;

        while(left < right && root_val != inorder[mid]){
            move++;
            mid++;
        }

        root -> left = helper(preorder, inorder, root_idx + 1, left, mid - 1);
        root -> right = helper(preorder, inorder, root_idx + move + 1, mid + 1, right);

        return root;
    }




    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0){
            return nullptr;
        }

        if (preorder.size() != inorder.size()){
            return nullptr;
        }

        return helper(preorder, inorder, 0, 0, preorder.size() - 1);
    }
};
