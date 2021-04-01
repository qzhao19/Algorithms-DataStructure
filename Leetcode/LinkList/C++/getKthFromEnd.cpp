/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) {
            return nullptr;
        }

        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;

        for (int i = 0; i < k; i++) {
            fast_ptr = fast_ptr -> next;
        }

        while (fast_ptr != NULL) {
            fast_ptr = fast_ptr -> next;
            slow_ptr = slow_ptr -> next;
        }

        return slow_ptr;
    }
};