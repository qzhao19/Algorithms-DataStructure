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
        // define a dummy head node
        
        
        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next =head;
        
        ListNode *cur_node = head;
        ListNode *prev_node = dummy_node;
        
        while (prev_node ->next != NULL){
            
            int counter = 0;
            
            while (cur_node != NULL && prev_node -> next -> val == cur_node -> val){
                
                counter++;
                cur_node = cur_node -> next;
            }
            
            if (counter == 1){
                prev_node = prev_node -> next;
            }else{
                prev_node -> next = cur_node;
            }
            
        }
        
        return dummy_node -> next;
        
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }

        map<int, int> hash_map;
        while (head != NULL) {
            hash_map[head -> val]++;
            head = head -> next;
        }

        ListNode *dummy_node = new ListNode(0);
        ListNode *cur_ptr = dummy_node;

        map<int, int>:: iterator iter;
        for (iter = hash_map.begin(); iter != hash_map.end(); iter++) {
            if (iter -> second == 1) {
                cur_ptr -> next = new ListNode(iter -> first);
                cur_ptr = cur_ptr -> next;
            }
        }

        return dummy_node -> next;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *dummy_node = new ListNode(0);
        dummy_node -> next = head;
        ListNode *cur_ptr = dummy_node;

        ListNode *ptr_1 = nullptr;
        ListNode *ptr_2 = nullptr;

        while (cur_ptr -> next != nullptr) {
            ptr_1 = cur_ptr -> next;
            ptr_2 = cur_ptr -> next;

            while (ptr_2 -> next != nullptr && ptr_2 -> next -> val == ptr_1 -> val) {
                ptr_2 = ptr_2 -> next;
            }
           
            if (ptr_1 == ptr_2) {
                cur_ptr = cur_ptr -> next;
            }
            else {
                cur_ptr -> next = ptr_2 -> next;
            }
        }

        return dummy_node -> next;
    }
};