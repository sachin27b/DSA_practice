//https://leetcode.com/problems/reverse-vowels-of-a-string/
class Solution {
public:
    string reverseVowels(string s) {

        int ptr1 = 0, ptr2 = s.size() - 1;
        bool flag1 = false, flag2 = false;
        unordered_map<char, int> map;
        map['a'] = 1;
        map['e'] = 1;
        map['i'] = 1;
        map['o'] = 1;
        map['u'] = 1;
        map['A'] = 1;
        map['E'] = 1;
        map['I'] = 1;
        map['O'] = 1;
        map['U'] = 1;
        while (ptr1 < ptr2) {
            if (map[s[ptr1]] != 1) {
                ptr1++;
                flag1 = false;
            } else
                flag1 = true;
            if (map[s[ptr2]] != 1) {
                ptr2--;
                flag2 = false;
            } else
                flag2 = true;
            if (flag1 && flag2) {
                swap(s[ptr1], s[ptr2]);
                ptr1++;
                ptr2--;
                flag1 = false;
                flag2 = false;
            }
        }
        return s;
    }
};
