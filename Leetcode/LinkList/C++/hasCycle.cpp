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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) {
            return false;
        }

        ListNode *fast_ptr = head -> next;
        ListNode *slow_ptr = head;

        while (fast_ptr != slow_ptr) {
            if (fast_ptr == NULL || fast_ptr -> next == NULL) {
                return false;
            }
            fast_ptr = fast_ptr -> next -> next;
            slow_ptr = slow_ptr -> next;
        }

        return true;
    }
};