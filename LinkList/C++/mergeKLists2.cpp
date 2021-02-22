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

        cur_ptr -> next = l1 ? l1 : l2;

        return dummy_node -> next;
    }

    ListNode *merge(vector<ListNode*> &lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        if (left > right) {
            return nullptr;
        }

        int mid = left + ((right - left) >> 1);
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};