class Solution {
public:
    //Function to return list containing vertices in Topological order.

    void TopSort(int node, vector<bool>& visited, stack<int>& st, vector<int> adj[]) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor])
                TopSort(neighbor, visited, st, adj);
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!visited[i])
                TopSort(i, visited, st, adj);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
