\\ https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node, int vis[], vector<int> adj[],vector<int> &dfs_call)
    {
        vis[node] = 1;
        dfs_call.push_back(node);
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj, dfs_call);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> dfs_call;
        dfs(start, vis, adj, dfs_call);
        
        return dfs_call;
    }
