/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        
        ListNode *node =head;
        stack<int> node_stack;
        
        while (node != NULL){
            node_stack.push(node -> val);
            node = node -> next;
        }
        
        vector<int> ans;
         while(!node_stack.empty()){
             ans.push_back(node_stack.top());
             node_stack.pop();
         }
        return ans;
    }
};
