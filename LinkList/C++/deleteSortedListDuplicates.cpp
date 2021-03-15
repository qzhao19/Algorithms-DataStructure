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
        
        ListNode *cur_node = head;
        
        while (cur_node != NULL && cur_node -> next != NULL){
            
            if (cur_node -> val == cur_node -> next -> val){
                
                cur_node -> next = cur_node -> next -> next;
            }else{
                
                cur_node = cur_node -> next;
            }
            
        }
        
        return head;
        
        
    }
};