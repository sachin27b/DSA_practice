//https://leetcode.com/problems/course-schedule/
//Using DFS topological Sort
class Solution {
public:
    bool dfs(int node, int recursionCalls[], vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        recursionCalls[node] = 1;
        for(auto it: adj[node])
        {
            if(vis[it] == 0)
            {
                if(dfs(it, recursionCalls, vis, adj) == false)
                {
                    return false;
                }
            }
            else if(vis[it] == 1 && recursionCalls[it] == 1)
            {
                return false;
            }
        }
        recursionCalls[node] = 0;
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // return true;

        int recursionCalls[numCourses];
        vector<int> vis(numCourses, 0);
        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i, recursionCalls, vis, adj) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

// Using Kahn's Algorithm BFS topological Sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (ans.size() == numCourses)
            return true;
        else
            return false;
    }
};
