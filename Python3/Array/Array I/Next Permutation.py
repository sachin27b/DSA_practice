from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        swap_idx = -1
        size = len(nums)
        for idx in range(size - 2, -1, -1):
            if(nums[idx] < nums[idx + 1]):
                swap_idx = idx
                break
        if(swap_idx != -1):
            for idx in range(size - 1, swap_idx, -1):
                if(nums[idx] > nums[swap_idx]):
                    nums[idx], nums[swap_idx] = nums[swap_idx], nums[idx]
                    break
            nums[swap_idx+1:] = reversed(nums[swap_idx+1:])
        else:
            nums.reverse()

class_obj = Solution()
nums = [3,2,1]
class_obj.nextPermutation(nums)
print(nums)