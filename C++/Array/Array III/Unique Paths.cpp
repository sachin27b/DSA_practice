\\ https://leetcode.com/problems/unique-paths/description/

\\Dynamic programming O(n*m)

class Solution {
public:
    
    int findPath(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        

        if(i >= m || j >= n)
        {
            return 0;
        }
        else if(i == m-1 && j == n-1)
        {
            return 1;
        }
        else if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        else
        {
            return dp[i][j] = findPath(i+1, j, m, n, dp) + findPath(i, j+1, m, n, dp);
        }


    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findPath(0, 0, m, n, dp);
    }
};

\\ Combinatorics solution O(n-1) or O(m-1)

    int uniquePaths(int m, int n) {

// number of "right" moves will be n-1 and "down" moves will be m-1 in a single path. Path length will always be m-1 + n-1. so it becomes a combinatorics problem i.e choosing from n-1 "right" moves from path length. or m-1 "down" moves from path length.

        int path_len = m + n - 2;
        double numerator = 1, denominator = 1;
        for(int i = 1; i < m; i++)
        {
            numerator = numerator * (path_len - (m - 1) + i);
            denominator = denominator * i;
        }

        return numerator/denominator;

    }
