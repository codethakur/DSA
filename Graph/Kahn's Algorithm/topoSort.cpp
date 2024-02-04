class Solution {
public:
    // Function to return list containing vertices in Topological order.

    // using Kahn's Algorithm
    vector<int> topoSort(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for (auto neighbor : adj[frontNode]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};
