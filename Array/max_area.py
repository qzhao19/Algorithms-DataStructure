class Solution:
    def maxArea(self, height: List[int]) -> int:
        """Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
        n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
        Find two lines, which together with x-axis forms a container, such that the container 
        contains the most water.
        
        """
        solution = 0
        left = 0
        right = len(height) - 1
        
        while (left < right):
            h = min(height[left], height[right])
            area = h * (right - left)
            solution = max(solution, area)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                
        return solution
        
