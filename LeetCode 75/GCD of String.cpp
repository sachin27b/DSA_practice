//https://leetcode.com/problems/greatest-common-divisor-of-strings/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // + operator can be used to concatenate string
        if(str1 + str2 == str2 + str1)// This concept of string equality
        {
            return str1.substr(0, gcd(str1.length(), str2.length()));
            //substr returns string from 0 to n-1
        }
        else
            return "";
    }
};
