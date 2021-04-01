class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        """Given an array nums of n integers and an integer target, find three integers in nums 
        such that the sum is closest to target. Return the sum of the three integers. You may assume 
        that each input would have exactly one solution.

        Example:
            Given array nums = [-1, 2, 1, -4], and target = 1.
            The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
        
        """
        
        if (nums is None) or (len(nums) < 3):
            return -1
        
        closest_sum = nums[0] + nums[1] + nums[2]
        # min_diff = abs(closest_sum - target)
        
        # sort array
        nums.sort()
        
        for i in range(0, len(nums)-2):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                cur_sum = nums[l] + nums[r] + nums[i]
                
                if abs(cur_sum - target) < abs(closest_sum - target):
                    closest_sum = cur_sum
                    
                if cur_sum == target:
                    # closest_sum = cur_sum
                    return cur_sum
                
                if cur_sum > target:
                    r -= 1
                else:
                    l += 1
                    
        return closest_sum
