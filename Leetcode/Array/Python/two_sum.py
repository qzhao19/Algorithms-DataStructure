class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for indice, value in enumerate(nums):
            hash_map[value] = indice
            
        for indice, value in enumerate(nums):
            if target - value in hash_map:
                if indice != hash_map[target-value]:
                    return indice, hash_map[target-value]
            
        
