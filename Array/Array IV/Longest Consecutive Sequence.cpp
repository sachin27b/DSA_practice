// https://leetcode.com/problems/longest-consecutive-sequence/description/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        if(nums.size() == 0)
            return 0;
       // using unordered_set because it can store unique elements. Hash map stores all the lements including copies. unordered set can then be used to find longest sequence. before checking if the next element exists in the set, check if predecessor exists or not. if it exists then it means that this element is not the first element of the sequence. 
        unordered_set<int> nums_set;
        int count = 1, longest_sequence = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            nums_set.insert(nums[i]);
        }

// at each element i check if its predecessor exists in the set or not. if it does not exist it means it is the first element in the sequence. so for this element we run a while loop till the point we cannot find the next element anymore. and after exiting the while loop update max sequence length.  
        for(auto it: nums_set)
        {
            if(nums_set.find(it - 1) == nums_set.end())
            {
                while(nums_set.find(it + count) != nums_set.end())
                {
                    count++;
                }

                longest_sequence = max(count, longest_sequence);
                count = 1; // because if after a successful iteration it enters another successful iteration then count should be reset before it starts again.
            }

            else
            {
                count = 1;
            }
        }

        return longest_sequence;
    }
};
