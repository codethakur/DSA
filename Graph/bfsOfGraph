class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
     void bfs(vector<int> adj[], vector<bool>& visited, vector<int>& ans, int startNode) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (int neighbor : adj[frontNode]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        vector<bool> visited(V, false);

        bfs(adj, visited, ans, 0);
        return ans;
    }
};
