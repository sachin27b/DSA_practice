\\https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // keep checking if compliment of the current element is present in
        // hash map or not. also add current element in the map.

        unordered_map<int, int> mpp;
        vector<int> ans;
        int comp;
        for(int i = 0; i < nums.size(); i++)
        {
            comp = target - nums[i];
            if(mpp.find(comp) != mpp.end())
            {
                ans.push_back(mpp[comp]);
                ans.push_back(i);

                return ans;
            }
            mpp[nums[i]] = i;
        }

        return ans;
    }

};
