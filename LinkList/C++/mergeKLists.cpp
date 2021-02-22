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

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL) {
            return l1 ? l1 : l2;
        }

        ListNode *dummy_node = new ListNode(0);
        ListNode *cur_ptr = dummy_node;

        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                cur_ptr -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur_ptr -> next = l2;
                l2 = l2 -> next;
            }
            cur_ptr = cur_ptr -> next;
        }
        cur_ptr -> next = (l1 ? l1 : l2);

        return dummy_node -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        ListNode *result = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }
};