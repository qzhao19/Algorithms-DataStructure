class Solution:
    def reverse(self, x: int) -> int:
        """Given a 32-bit signed integer, reverse digits of an integer.
        Example 1:
            Input: 123
            Output: 321  
            
        """
        solution = 0
        
        if x < 0:
            flag = -1
        else:
            flag = 1
        
        while x>0:
            solution = solution*10 +  x%10
            x //= 10
            
        solution = flag * solution
        
        if solution <= -2**31 or solution >= 2**31 - 1:
            return 0
        else:
            return solution
