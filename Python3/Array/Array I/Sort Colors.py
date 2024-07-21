# https://leetcode.com/problems/sort-colors/description/

from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        low = 0
        mid = 0
        high = len(nums) - 1
        """
        0 - low -1 ---> 0's
        low - mid ---> 1's
        high + 1 - size ---> 2's
        """
        while mid <= high:
            if nums[mid] == 0:
                nums[mid], nums[low] = nums[low], nums[mid]
                mid += 1
                low += 1
            elif nums[mid] == 1:
                mid += 1
            else:  # nums[mid] == 2
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1


class_obj = Solution()

nums = [2,0,2,1,1,0]
class_obj.sortColors(nums)

print(nums)
