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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return l1 ? l1 : l2;
        }

        stack<int> stk1;
        stack<int> stk2;

        while (l1 != NULL) {
            stk1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2 != NULL) {
            stk2.push(l2 -> val);
            l2 = l2 -> next;
        }

        ListNode *head = nullptr;
        int sum = 0;

        while (!stk1.empty() || !stk2.empty() || sum > 0) {
            if (!stk1.empty()) {
                sum += stk1.top(); stk1.pop();
            }

            if (!stk2.empty()) {
                sum += stk2.top(); stk2.pop();
            }

            ListNode *cur_node = new ListNode(sum % 10);
            sum /= 10;
            cur_node -> next = head;
            head = cur_node;
        }

        return head;
    }
};