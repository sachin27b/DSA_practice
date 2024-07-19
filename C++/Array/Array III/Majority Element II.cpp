\\https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // maximum number of elements that can appear more than n/3 times is 2.

        int maj_element1 = INT_MIN, count1 = 0;
        int maj_element2 = INT_MIN, count2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maj_element1)
            {
                count1++;
            }
            else if(nums[i] == maj_element2)
            {
                count2++;
            }
            else if(count1 == 0 && nums[i] != maj_element2)
            {
                maj_element1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != maj_element1)
            {
                maj_element2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
    count1 = 0;
    count2 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == maj_element1)
            count1++;
        if(nums[i] == maj_element2)
            count2++;
        
    }
    vector<int> ans;

    if(count1 > nums.size()/3)
        ans.push_back(maj_element1);
    if(count2 > nums.size()/3)
        ans.push_back(maj_element2);
    
    return ans;
    }
};
