//https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0)
            {
                swap(nums[i], nums[ptr1]);
                ptr1++;
            }
        }
    }
};
