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
    pair<ListNode*, ListNode*> reverseOneGroup(ListNode *head, ListNode *tail) {
        ListNode *prev_node = tail -> next;
        ListNode *cur_node = head;

        while (prev_node != tail) {
            ListNode *succ_node = cur_node -> next;
            cur_node -> next = prev_node;
            prev_node = cur_node;
            cur_node = succ_node;
        }

        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head;
        ListNode *prev_node = dummy_node;

        while (prev_node -> next != NULL) {
            ListNode *tail = prev_node;

            for (int i = 0; i < k; i++) {
                tail = tail -> next;
                if (tail == NULL) {
                    return dummy_node -> next;
                }
            }

            ListNode *succ_node = tail -> next;
            tie(head, tail) = reverseOneGroup(head, tail);

            prev_node -> next = head;
            tail -> next = succ_node;
            prev_node = tail;
            head = tail -> next;

        }
        
        return dummy_node -> next;
    }
};