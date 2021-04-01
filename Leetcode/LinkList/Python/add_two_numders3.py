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
        cur_list = solution
        carry = 0
        while l1 or l2:
            
            cur_val = l1.val + l2.val + carry
            cur_list.val = cur_val % 10
            
            if cur_val > 9:
                carry = 1
            else:
                carry = 0
            
            if l1.next is None and l2.next is None and carry == 0:
                break
                
            if l1.next is None:
                l1.next = ListNode(0)
                
            if l2.next is None:
                l2.next = ListNode(0)
            
            l1 = l1.next
            l2 = l2.next
            cur_list.next = ListNode(0)
            cur_list = cur_list.next
            
        return solution   
        
