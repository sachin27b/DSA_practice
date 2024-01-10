//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, i = 0;
        while(i <= high)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[low]);
                low++; 
                i++;
            }
            else if(nums[i] == 1)
            {
                i++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i], nums[high]);
                high--;
            }
        }
    }
};
