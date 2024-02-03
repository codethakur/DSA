class Solution {
public:
    // Recursive function to perform DFS traversal
    void dfs(vector<int> adj[], vector<bool>& visited, vector<int>& ans, int currentNode) {
        // Mark the current node as visited
        visited[currentNode] = true;
        
        // Add the current node to the result
        ans.push_back(currentNode);
        
        // Visit all neighbors of the current node
        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                dfs(adj, visited, ans, neighbor);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(V, false);

        // Start DFS from the 0th vertex
        dfs(adj, visited, ans, 0);

        return ans;
    }
};
