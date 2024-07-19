https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        for(int i = 0; i < t.length(); i++)
        {
            if(t[i] == s[ptr])
            {
                ptr++;
            }
        }
        if(ptr == s.length())
            return true;
        else
            return false;
    }
};
