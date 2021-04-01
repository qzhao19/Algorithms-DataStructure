# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        """Given a linked list, swap every two adjacent nodes and return its head.
        You may not modify the values in the list's nodes, only nodes itself may be changed.

        Example:
            Given 1->2->3->4, you should return the list as 2->1->4->3.
        """
        if head is None or head.next is None:
            return head
        
        dummy = ListNode(0)
        
        dummy.next = head
        
        prev_node, cur_node = dummy, head
        
        while cur_node and cur_node.next:
            
            prev_node.next = cur_node.next
            
            cur_node.next = prev_node.next.next
            
            prev_node.next.next = cur_node
            
            prev_node, cur_node = cur_node, cur_node.next
            
        return dummy.next
            
            
        
        
            
