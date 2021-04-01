class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        
        Implement next permutation, which rearranges numbers into the lexicographically next greater 
        permutation of numbers.

        If such arrangement is not possible, it must rearrange it as the lowest possible 
        order (ie, sorted in ascending order).

        The replacement must be in-place and use only constant extra memory.

        Here are some examples. Inputs are in the left-hand column and its corresponding outputs 
        are in the right-hand column.

        1,2,3 → 1,3,2
        3,2,1 → 1,2,3
        1,1,5 → 1,5,1
        """
        
        if len(nums) < 0:
            return
        
        i = len(nums)-1
        while i-1>=0 and nums[i-1]>=nums[i]:
            i -=1
        #>left
        if i-1>=0:
            j = i
            while j<len(nums) and nums[j]>nums[i-1]:
                j +=1
            #swap the min-max number
            nums[i-1],nums[j-1] = nums[j-1],nums[i-1]
        m = i
        n = len(nums)-1
        while m < n:
            nums[m],nums[n] = nums[n],nums[m]
            m +=1
            n -=1
            
        
