// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // exception case 
        if (head == NULL){
            return NULL;
        }
        
        
        // define a current node 
        ListNode *cur_node = head;
        ListNode *prev_node = head;
        
        // define a counter 
        int count = 0;
        
        while (cur_node != NULL){
            count++;
            cur_node = cur_node -> next;
        }
        int n_inorder = count - n;
        
        // in this case, it means that we need to delte head
        if (n_inorder == 0){
            head = head -> next;
            return head;
        }
        
        for (int i = 0; i < count - 1; i++){
            if (i == n_inorder - 1){
                
                prev_node -> next = prev_node -> next -> next;
                break;
            }
            prev_node = prev_node -> next;
            
        }
        return head;
        
        
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head;

        ListNode *fast_ptr = dummy_node -> next;
        ListNode *slow_ptr = dummy_node;

        for (int i = 0; i < n; i++) {
            fast_ptr = fast_ptr -> next;
        }

        while (fast_ptr != NULL) {
            fast_ptr = fast_ptr -> next;
            slow_ptr = slow_ptr -> next;
        }

        slow_ptr -> next = slow_ptr -> next -> next;

        return dummy_node -> next;
    }
};