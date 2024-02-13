//Shortest Path in Undirected Graphs

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph {
public:
	unordered_map<int, list<int>> connection;

	void addAdj(int u, int v, bool direction)
	{
		connection[u].push_back(v);
		if (!direction) {
			connection[v].push_back(u);
		}
	}

	vector<int> shortestDistance(int source, int Destination)
	{
		unordered_map<int, bool> visited;
		unordered_map<int, int> parent;
		queue<int> q;

		q.push(source);
		visited[source] = true;
		parent[source] = -1;

		while (!q.empty())
		{
			int currentNode = q.front();
			q.pop();

			for (auto neighbor : connection[currentNode])
			{
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					parent[neighbor] = currentNode;
					q.push(neighbor);
				}
			}
		}
		vector<int> ans;
		int currentNode = Destination;
		ans.push_back(Destination);

		while (currentNode != source)
		{
			currentNode = parent[currentNode];
			ans.push_back(currentNode);
		}
		reverse(ans.begin(), ans.end());
		return ans;
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
	cout << "Enter the number of node: " << endl;
	cin >> n;

	int m;
	cout << "Enter the number of edges:" << endl;
	cin >> m;

	Graph g;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g.addAdj(u, v, true);

	}
	cout << "Graph representation:" << endl;
	g.printGraph();
	cout << endl;

	int source;
	cout << "Enter the source: " << endl;
	cin >> source;
	int destination;
	cout << "Enter the destination: " << endl;
	cin >> destination;


	vector<int> ans = g.shortestDistance(source, destination);

	for (auto i : ans)
	{
		cout << i << " ";
	}

	system("pause>0");	

}
