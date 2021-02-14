/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *helper(vector<int> &nums, int left, int right){

        if (left > right) {
            return nullptr;
        }
        int mid = left + ((right - left) >> 1);

        TreeNode *root = new TreeNode(nums[mid]);

        root -> left = helper(nums, left, mid - 1);
        root -> right = helper(nums, mid + 1, right);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> node_array;

        if (head == NULL) {
            return nullptr;
        }

        while (head != NULL) {
            node_array.push_back(head -> val);
            head = head -> next;
        }

        return helper(node_array, 0, node_array.size() - 1);

    }
};