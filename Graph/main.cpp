#include<iostream>
#include<set>
#include<unordered_map>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class graph {
public:

    unordered_map<int, set<int>> connection;

    void addAdj(int u, int v, bool direction)
    {
        connection[u].insert(v);
        if (!direction) {
            connection[v].insert(u);
        }
    }

    void BFS(int startNode)
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto& neighbor : connection[frontNode])
            {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // Print the BFS result
        cout << "BFS Traversal: ";
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }

    void DFS(int startNode)
    {
        unordered_map<int, bool> visited;
        vector<int> ans;
        stack<int> s;

        s.push(startNode);
        visited[startNode] = true;

        while (!s.empty())
        {
            int currentNode = s.top();
            s.pop();

            ans.push_back(currentNode);

            for (auto& neighbor : connection[currentNode])
            {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // Print the DFS result
        cout << "DFS Traversal: ";
        for (int node : ans) {
            cout << node << " ";
        }
        cout << endl;
    }

    bool isCycleByBFS(int startNode)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;
        parent[startNode] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (int neighbor : connection[frontNode])
            {
                if (visited[neighbor] == true && neighbor != parent[frontNode]) {
                    cout << "Cycle detected by BFS." << endl;
                    return true;
                }
                else if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = frontNode;
                }
            }
        }
        cout << "No cycle detected by BFS." << endl;
        return false;
    }

    bool isCycleByDFS(int startNode)
    {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // Reset visited map for each DFS call
        for (auto& node : connection)
        {
            visited[node.first] = false;
        }

        return DFSHelper(startNode, visited, parent);
    }

    bool DFSHelper(int currentNode, unordered_map<int, bool>& visited, unordered_map<int, int>& parent)
    {
        visited[currentNode] = true;

        for (auto neighbor : connection[currentNode])
        {
            if (!visited[neighbor]) {
                parent[neighbor] = currentNode;
                bool cycle = DFSHelper(neighbor, visited, parent);
                if (cycle) {
                    cout << "Cycle detected by DFS." << endl;
                    return true;
                }
            }
            else if (neighbor != parent[currentNode]) {
                cout << "Cycle detected by DFS." << endl;
                return true;
            }
        }
        return false; // No cycle detected in this DFS traversal
    }


    void printGraph()
    {
        for (auto i : connection)
        {
            cout << i.first << "->";
            if (!i.second.empty())
            {
                auto it = i.second.begin();
                cout << *it;
                ++it;
                for (; it != i.second.end(); ++it)
                {
                    cout << "," << *it;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph G;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G.addAdj(u, v, true);  // Assuming directed graph
    }

    cout << "Graph representation:" << endl;
    G.printGraph();
    cout << endl;

    int startNode;
    cout << "Enter the starting node for Traversal : " << endl;
    cin >> startNode;

    G.BFS(startNode);
    G.DFS(startNode);
    cout << endl;

    cout << "Detect cycle in a inrected graph using BFS" << endl;
    G.isCycleByBFS(startNode);
    cout << endl;

    cout << "Detect cycle in a inrected graph using DFS" << endl;
    G.isCycleByDFS(startNode);
    cout << endl;

    system("pause>0");
}
