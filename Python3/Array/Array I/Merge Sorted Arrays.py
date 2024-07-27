from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if(m == 0):
            nums1[0:n-1] = nums2[0:m-1]
        arr_ptr = m + n - 1
        ptr1 = m - 1
        ptr2 = n - 1
        while(ptr1 >= 0 and ptr2 >= 0):
            if(nums1[ptr1] > nums2[ptr2]):
                nums1[arr_ptr] = nums1[ptr1]
                ptr1 -= 1
            else:
                nums1[arr_ptr] = nums2[ptr2]
                ptr2 -= 1
            arr_ptr -= 1

        if(ptr2 >= 0):
            nums1[ptr1+1:arr_ptr+1] = nums2[0:ptr2+1]



            
class_obj = Solution()
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3
class_obj.merge(nums1,m,nums2,n)
print(nums1)


         