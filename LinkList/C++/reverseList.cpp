/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return nullptr;
        }

        ListNode *prev_ptr = nullptr;
        ListNode *cur_ptr = head;

        while (cur_ptr != NULL) {
            ListNode *succ_ptr = cur_ptr -> next;
            cur_ptr -> next = prev_ptr;
            prev_ptr = cur_ptr;
            cur_ptr = succ_ptr;
        }

        return prev_ptr;
    }
};