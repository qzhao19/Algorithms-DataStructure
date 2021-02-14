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
    bool helper(TreeNode *A, TreeNode *B){
        if (B == NULL) return true;
        if (A == NULL || A -> val != B -> val){
            return false;
        }

        return helper(A -> left, B -> left) && helper(A -> right, B -> right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) return false;

        return helper(A, B) || isSubStructure(A -> left, B) || isSubStructure(A -> right, B);

    }
};