class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // using Kahn's Algorithm
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V, 0);
            for (int i = 0; i < V; i++) {
                for (auto j : adj[i]) {
                    indegree[j]++;
                }
            }

        // Initialize a queue for topological sorting.
        queue<int> q;

        // Count of visited nodes during topological sorting.
        int visitedCount = 0;

        // Enqueue nodes with indegree 0.
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting.
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            visitedCount++;

            for (auto neighbor : adj[frontNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the visited count is less than the number of nodes, there is a cycle.
        return (visitedCount < V);    
    }
};
