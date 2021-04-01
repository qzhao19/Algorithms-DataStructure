# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        """Merge two sorted linked lists and return it as a new list. 
        The new list should be made by splicing together the nodes of the first two lists.

        Example:
            Input: 1->2->4, 1->3->4
            Output: 1->1->2->3->4->4
        """
        dummy = ListNode(0)
        
        curr_node = dummy
        
        if l1 is None: 
            return l2
        
        if l2 is None:
            return l1
        
        while l1 and l2:
            is_small = l1.val < l2.val
            
            curr_node.next = l1 if is_small else l2
            curr_node = curr_node.next
            
            l1 = l1.next if is_small else l1
            l2 = l2 if is_small else l2.next
            
        curr_node = l2 if l1 is None else l1
        
        return dummy.next
    
    
    # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        """Merge two sorted linked lists and return it as a new list. 
        The new list should be made by splicing together the nodes of the first two lists.

        Example:
            Input: 1->2->4, 1->3->4
            Output: 1->1->2->3->4->4
        """
        dummy = ListNode(0)
        
        cur_node = dummy
        
        if l1 is None: 
            return l2
        
        if l2 is None:
            return l1
        
        while l1 is not None and l2 is not None:
            if l1.val > l2.val:
                dummy.next = l2
                l2 = l2.next
            else:
                dummy.next = l1
                l1 = l1.next
                
            dummy = dummy.next
            
        if l1 is None:
            dummy.next = l2
        if l2 is None:
            dummy.next = l1
                
        return cur_node.next
        
        
    
