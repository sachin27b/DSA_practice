//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_element = candies[0];
        int size = candies.size();
        vector<bool> result(size);
        /*you only need to check if the sum is greater than the greatest
        element in the candies array*/
        for (int i = 1; i < candies.size(); i++) {
            max_element = max(max_element, candies[i]);
        }
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max_element) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};
