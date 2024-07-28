# https://leetcode.com/problems/find-the-duplicate-number/

from typing import List
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow_ptr = 0
        fast_ptr = 0
        flag = 0

        while(nums[slow_ptr] != nums[fast_ptr] or flag == 0):
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[nums[fast_ptr]]
            flag = 1
        
        fast_ptr = 0
        
        while(nums[slow_ptr] != nums[fast_ptr]):
            slow_ptr = nums[slow_ptr]
            fast_ptr = nums[fast_ptr]

        return nums[slow_ptr]

class_obj = Solution()
nums = [1,3,4,2,2]
print(class_obj.findDuplicate(nums))
