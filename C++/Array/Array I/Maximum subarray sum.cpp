//https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int curr_sum = 0, global_sum = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            if(curr_sum > global_sum)
            {
                global_sum = curr_sum;
            }

            if(curr_sum < 0)
            {
                curr_sum = 0;
            }

        }

        return global_sum;
    }
};