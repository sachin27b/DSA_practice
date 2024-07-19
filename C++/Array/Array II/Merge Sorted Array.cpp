// https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m == 0)
        {
            for(int i = 0; i < n; i++)
            {
                nums1.at(i) = nums2.at(i);
            }
        }
        else if(n != 0)
        {
            while(m > 0 && n > 0)
            {
                if(nums1.at(m-1) > nums2.at(n-1))
                {
                    nums1.at(m+n-1) = nums1.at(m-1);
                    m -= 1;
                }
                else
                {
                    nums1.at(m+n-1) = nums2.at(n-1);
                    n -= 1; 
                }
            }

            if(n > 0)
            {
                int k = 0;
                for(int i = 0; i < n; i++)
                {
                    nums1.at(k++) = nums2.at(i);
                }
            }
        }
    }
        
};
