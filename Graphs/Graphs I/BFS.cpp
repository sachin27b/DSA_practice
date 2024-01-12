\\ https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int vis[], vector<int> adj[], vector<int> &bfs_call)
    {
        queue<int> q;
        int start = 0;
        vis[start] = 1;
        q.push(start);
        
        while(!q.empty())
        {
            
            int node = q.front();
            q.pop();
            bfs_call.push_back(node);
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        int vis[V] = {0};
        
        vector<int> bfs_call;
        
        bfs(vis, adj, bfs_call);
        
        return bfs_call;
        
    }
};
