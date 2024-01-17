//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* We will use sliding window. There will be a left pointer and a right
        pointer. The left pointer will always point to the element next to the
        repeating element. We will store all the elements seen in an unordered_map.
        It will contain the elements and the index it was last seen at.*/

        unordered_map<char, int> elements;
        int count = 0, max_length = 1, left = 0;

        if(s.length() == 0)
            return 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(elements.find(s[i]) != elements.end() && (elements[s[i]] >= left))
            {
                left = elements[s[i]] + 1; // moving left pointer if copy found in map
                elements[s[i]] = i; //updating the index of element seen again
                count = i - left + 1; // new length will be from left to current index
            }
            else
            {
                elements[s[i]] = i;
                count++;
                max_length = max(count, max_length);
            }
        }

        return max_length;
    }
};
