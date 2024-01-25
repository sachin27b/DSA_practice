//https://leetcode.com/problems/merge-strings-alternately/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int w1 = 0, w2 = 0, i = 0;
        string merged = "";
        while(w1 < n && w2 < m)
        {
            merged += word1[w1];
            // i++;
            merged += word2[w2];
            // i++;
            w1++;
            w2++;
        }
        if(w1 == n)
        {
            for(int i = w2; i < m; i++)
            {
                merged += word2[i];
            }
        }
        if(w2 == m)
        {
            for(int i = w1; i < n; i++)
            {
                merged += word1[i];
            }
        }

        return merged;
    }
};
