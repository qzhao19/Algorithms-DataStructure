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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_node = new ListNode(0);
        ListNode *cur_ptr = dummy_node;
        int sum = 0;

        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }

            if (l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            cur_ptr -> next = new ListNode(sum%10);
            cur_ptr = cur_ptr -> next;
            sum /= 10;
        }

        return dummy_node -> next;

    }
};