class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for indice1, value1 in enumerate(nums):
            for indice2, value2 in enumerate(nums):
                if ((value1 + value2) == target) & (indice1 != indice2):
                    return indice1, indice2
                    
            
        
