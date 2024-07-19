# https://leetcode.com/problems/maximum-subarray/description/
from typing import List

import sys
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_sum = -sys.maxsize - 1
        current_sum = 0

        for idx in range(len(nums)):
            current_sum += nums[idx]
            if(global_sum < current_sum):
                global_sum = current_sum
            if(current_sum < 0):
                current_sum = 0
        
        return global_sum

if __name__ == "__main__":
    
    class_obj = Solution()
    print(class_obj.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))