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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return nullptr;
        }

        unordered_set<ListNode *> hash_set;

        while (head != NULL) {
            if (hash_set.count(head)) {
                return head;
            }

            hash_set.insert(head);
            head = head -> next;
        }

        return nullptr;
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;

        while (true) {
            if (fast_ptr == NULL || fast_ptr -> next == NULL) {
                return nullptr;
            }

            fast_ptr = fast_ptr -> next -> next;
            slow_ptr = slow_ptr -> next;

            if (fast_ptr == slow_ptr) {
                break;
            }
        }

        fast_ptr = head;
        while (fast_ptr != slow_ptr) {
            fast_ptr = fast_ptr -> next;
            slow_ptr = slow_ptr -> next;
        }

        return fast_ptr;
    }
};