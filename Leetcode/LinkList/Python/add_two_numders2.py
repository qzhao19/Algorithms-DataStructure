# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    
    Example:
        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
        Explanation: 342 + 465 = 807.

    """
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        solution = ListNode(0)
        cur_node = solution
        while l1 or l2:
            # cur_node.val += self.addTwoNodes(l1, l2)
            
            cur_node.val = l1.val +l2.val
            if cur_node.val >= 10:
                cur_node.val -= 10
                cur_node.next = ListNode(1)
            else:
                if l1 and l1.next or l2 and l2.next:
                    cur_node = ListNode(0)
            cur_node = cur_node.next
            
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
                
        return solution
    
    def addTwoNodes(self, node1, node2):
        """
        
        """
        if not node1 and not node2:
            None
            
        if not node1:
            return node2.val
        
        if not node2:
            return node1.val
        
        return node1.val + node2.val
    
        
        
        
