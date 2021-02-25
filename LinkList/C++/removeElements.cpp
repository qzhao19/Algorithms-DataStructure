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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head; 
            
        ListNode *prev_node = dummy_node;
        
        while (prev_node -> next != NULL){
            
            if (prev_node -> next -> val == val){
                prev_node -> next = prev_node -> next -> next;
            }else{
                prev_node  = prev_node -> next;
            }
            
        }
        return dummy_node -> next;
        
    }
};