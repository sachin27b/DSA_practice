//https://leetcode.com/problems/is-graph-bipartite/description/
class Solution {
public:
    bool checkBipartite(vector<vector<int>> & graph, queue<int> &q, vector<int> &color) {
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1 && color[node] == 0) {
                    q.push(it);
                    color[it] = 1;
                }

                else if (color[it] == -1 && color[node] == 1) {
                    q.push(it);
                    color[it] = 0;
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {
            if(color[i] == -1)
            {
                q.push(i);
                color[i] = 0;
                if(checkBipartite(graph, q, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
