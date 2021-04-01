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
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        vector<ListNode *> node_vect;

        while (head != NULL) {
            node_vect.push_back(head);
            head = head -> next;
        }  

        int i = 0, j = node_vect.size() - 1;


        while (i < j) {
            if (node_vect[i] -> val != node_vect[j] -> val) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};