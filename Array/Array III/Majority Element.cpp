\\ https://leetcode.com/problems/majority-element/description/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int maj_element = nums[0], count = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == maj_element)
            {
                count++;
            }
            else if(count == 0)
            {
                maj_element = nums[i];
            }
            else
            {
                count--;
            }
        }
        return maj_element;
    }
};
