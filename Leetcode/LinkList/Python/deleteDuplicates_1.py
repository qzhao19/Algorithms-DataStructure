# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """Given a sorted linked list, delete all duplicates such that each element appear only once.
        Example 1:
            Input: 1->1->2
            Output: 1->2
        """
        
        if not head:
            return head
        
        cur_node = head
        while cur_node is not None:
            if cur_node.next is None or cur_node.val != cur_node.next.val:
                cur_node = cur_node.next
            else:
                cur_node.next = cur_node.next.next
        
        return head
            
