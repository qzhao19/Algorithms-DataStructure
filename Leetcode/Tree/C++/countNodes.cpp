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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};



class Solution {
public:
    int getDepth(TreeNode *root) {
        int depth = 0;
        while (root -> left != nullptr) {
            root = root -> left;
            depth++;
        }
        return depth;
    }

    bool isExistIndex(TreeNode *root, int depth, int index) {
        int bits = 1 << (depth - 1);
        TreeNode *cur_node = root;

        while (cur_node != nullptr && bits > 0) {
            if (!(bits & index)) {
                cur_node = cur_node -> left;
            }
            else {
                cur_node = cur_node -> right;
            }
            bits >>= 1;
        }

        return cur_node == nullptr;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = getDepth(root);

        int left = 1 << depth, right = (1 << (depth + 1)) - 1;
        int mid;
        while (left < right) {
            mid = left + ((right - left + 1) >> 1);
            if (isExistIndex(root, depth, mid) == false) {
                left = mid; 
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};









