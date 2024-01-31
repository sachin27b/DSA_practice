//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0, j = 0;
        int n = s.length();
        while(i < n)
        {

            while(i < n && s[i] == ' ')
            {
                i++;
            }
            j = i;
            while(j < n && s[j] != ' ')
            {
                j++;
            }
            if(i < n)
            {
                ans = s.substr(i, j-i) + " " + ans;
                i = j + 1;
            }

        }
        return ans.substr(0, ans.length()-1);
    }
};
