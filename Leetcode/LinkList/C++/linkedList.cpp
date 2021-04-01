class MyLinkedList {
public:
    
    // the size of list and sinle_linked list node struct 
    int size;
    struct ListNode{
        int val; // node value 
        ListNode *next;  // next point
        
        ListNode(): val(0), next(nullptr) {}
        ListNode(int val): val(val), next(nullptr) {}
        ListNode(int val, ListNode *next): val(val), next(next) {}
    };
    
    ListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // checkout if list size
        if (size < 0 || index >= size){
            return -1;
        }
        
        // define a current node, which points to head next
        ListNode *cur_node = head -> next;
        for (int i = 0; i < index; i++){
            cur_node = cur_node -> next;
        }
        return cur_node -> val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        // checkout if index is bigger than size
        if (index > size){
            return;
        }
        if (index < 0){
            index = 0;
        }
        
        // a new node
        ListNode *node = new ListNode(val);
        // define a prev and current node
        ListNode *prev_node = head;
        ListNode *cur_node = head -> next; 
        
        for (int i = 0; i < index; i++){
            prev_node = cur_node;
            cur_node = cur_node -> next;
        }
        prev_node -> next = node;
        node -> next = cur_node;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // checkout size
        
        if (index >= size || index < 0){
            return ;
        }
        // define prev_node, cur_node
        ListNode *prev_node = head;
        ListNode *cur_node = head -> next;
        
        for (int  i = 0; i < index; i++){
            prev_node = cur_node;
            cur_node = cur_node -> next;
        }
        prev_node -> next = cur_node -> next;
        delete cur_node;
        size--;
        
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */












