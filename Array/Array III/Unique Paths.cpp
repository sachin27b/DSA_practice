\\ https://leetcode.com/problems/unique-paths/description/
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
