/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public: 
    int getListLength(ListNode *head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head -> next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return headA ? headA : headB;
        }

        int len_A = getListLength(headA);
        int len_B = getListLength(headB);

        if (len_A < len_B) {
            for (int i = 0; i < (len_B - len_A); i++) {
                headB = headB -> next;
            }
        }

        if (len_A > len_B) {
            for (int i = 0; i < (len_A - len_B); i++) {
                headA = headA -> next;
            }
        }

        while (headA != nullptr && headB != nullptr && headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }

        return headA == headB ? headA : nullptr;
    }
};