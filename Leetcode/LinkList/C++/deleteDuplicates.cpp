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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head;
        ListNode *cur_ptr = head;

        while (cur_ptr != nullptr && cur_ptr -> next != nullptr) {
            if (cur_ptr -> val == cur_ptr -> next -> val) {
                cur_ptr -> next = cur_ptr -> next -> next;
            }
            else {
                cur_ptr = cur_ptr -> next;
            }
        }

        return dummy_node -> next;
    }
};