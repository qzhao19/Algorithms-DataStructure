class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    
    # def print_nodes(self):
    #     if self is None:
    #         return 
    #     while self.next is not None:
    #         print(self.val)
    #         self = self.next
    #     print(self.val)

    def print_nodes(self):
        print(self.val)
        if self.next:
            self.next.print_nodes()
        

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
    def convert(self, l):
        solution = ''
        while l is not None:
            solution += str(l.val)
            l = l.next
        return int(solution)
        
    def add_numbers(self, l1, l2):
        num1, num2 = self.convert(l1), self.convert(l2)
        num = num1 + num2 

        root = Node(num%10)
        new_list = root
        num = num // 10
        while num != 0:
            new_list = Node(num%10)
            new_list = new_list.next
            num = num // 10

        return root

