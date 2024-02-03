////////////////////////  DFS-based algorithm  ////////////////////////
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], vector<bool>& visited, int currentNode, int parent) {
        visited[currentNode] = true;

        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                if (dfs(adj, visited, neighbor, currentNode))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfs(adj, visited, i, -1)) {
                return true;
            }
        }

        return false;
    }
};
////////////////////////  BFS-based algorithm  ////////////////////////
class Solution {
  public:
    bool bfs(vector<int> adj[],  vector<bool>&visited, int startNode)
    {
        visited[startNode]=1;
        queue<pair<int,int>>q;
        q.push({startNode,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            for(auto adjacent:adj[node])
            {
                if(!visited[adjacent])
                {
                    visited[adjacent]=1;
                    q.push({adjacent,node});
                }
                else if(adjacent != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(bfs(adj,visited, i)) return true;
            }
        }
        return false;
    }
};
