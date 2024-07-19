//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(j+1 < grid[0].size() && grid[i][j+1] == '1' && vis[i][j+1] != 1)
            {
                vis[i][j+1] = 1;
                q.push({i, j+1});
            }
            if(i+1 < grid.size() && grid[i+1][j] == '1' && vis[i+1][j] != 1)
            {
                vis[i+1][j] = 1;
                q.push({i+1, j});
            }
            if(i-1 >= 0 && grid[i-1][j] == '1' && vis[i-1][j] != 1)
            {
                vis[i-1][j] = 1;
                q.push({i-1, j});
            }
            if(j-1 >= 0 && grid[i][j-1] == '1' && vis[i][j-1] != 1)
            {
                vis[i][j-1] = 1;
                q.push({i, j-1});
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                    bfs(q, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
