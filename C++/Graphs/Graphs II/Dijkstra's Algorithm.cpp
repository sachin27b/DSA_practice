//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution
{
    //include <bits/stdc++>
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> parent(V, -1);
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        parent[S] = 0;
        /*in this question parent is not required. parent is used when 
        we want the shortest path and its weights.*/
        
        q.push({0,S});
        while(!q.empty())
        {
            int node = q.top().second;
            int distanceTillNode = q.top().first;
            q.pop();
            for(auto it: adj[node])
            {
                if(dist[it[0]] > distanceTillNode + it[1])
                {
                    dist[it[0]] = distanceTillNode + it[1];
                    parent[it[0]] = node;
                    q.push({dist[it[0]], it[0]});
                }
            }
            
        }
        
        return dist;
    }
};
