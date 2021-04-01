
// Definition for singly-linked list.
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL || k < 0) {
            return head;
        }

        int count = 1;
        ListNode *tmp = head;

        while (tmp -> next != NULL) {
            count++;
            tmp = tmp -> next;
        }

        k %= count;

        if (k == 0) {
            return head;
        }

        // ListNode *second = head;
        tmp -> next = head;
        for (int i = 0; i < count - k; i++) {
            tmp = tmp -> next;
        }

        ListNode *new_head = tmp -> next;
        tmp -> next = nullptr;

        return new_head;
    }
};