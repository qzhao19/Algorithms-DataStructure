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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
            return nullptr;
        }

        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head;
        ListNode *prev_ptr = dummy_node;

        while (prev_ptr -> next != NULL && prev_ptr -> next -> next != NULL) {
            ListNode *cur_ptr = prev_ptr -> next;
            ListNode *succ_ptr = prev_ptr -> next -> next;

            prev_ptr -> next = succ_ptr;
            cur_ptr -> next = succ_ptr -> next;
            succ_ptr -> next = cur_ptr;

            prev_ptr = prev_ptr -> next -> next;
        }

        return dummy_node -> next;
    }
};