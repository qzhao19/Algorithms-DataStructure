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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return ;
        }

        vector<ListNode*> list_vec;
        while (head != nullptr) {
            list_vec.push_back(head);
            head = head -> next;
        }

        int n = list_vec.size();
        int left = 0, right = n - 1;

        while (left < right) {
            list_vec[left] -> next = list_vec[right];
            left++;

            if (left == right) {
                break;
            }

            list_vec[right] -> next = list_vec[left];
            right--;
        }

        list_vec[left] -> next = nullptr;
    }
};