#include <iostream> 
#include <unordered_map> 
#include<list>
#include<vector>
#include<set>
using namespace std;
class Graph {
public:
	unordered_map<int, list<pair<int,int>>>connection;
	void addEdges(int u, int v, int w)
	{
		connection[u].emplace_back(v, w);
		connection[v].emplace_back(u, w);
	}
	vector<int>DijkstraAlgorithm(vector<int>& distance, set<pair<int, int>>& st, int sources)
	{
		distance[sources] = 0;
		st.insert(make_pair(0, sources));

		while (!st.empty())
		{
			auto topNode = *(st.begin());

			int nodeDis = topNode.first;
			int currNode = topNode.second;

			st.erase(st.begin());

			for (auto neighbor : connection[topNode.second])
			{
				if (nodeDis + neighbor.second < distance[neighbor.first]) {
					
					auto record = st.find(make_pair(distance[neighbor.first], neighbor.first));
					if (record != st.end()) {
						st.erase(record);
					}
					distance[neighbor.first] = nodeDis + neighbor.second;
					st.insert(make_pair(distance[neighbor.first], neighbor.first));

				}
			}

		}
		return distance;
		
	}
	

}; 

int main() {
	int n;
	std::cout << "Enter the number of nodes: ";
	std::cin >> n;

	int m;
	std::cout << "Enter the number of Edges: ";
	std::cin >> m;

	Graph g;
	std::cout << "Enter the edges (u v w):" << std::endl;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		g.addEdges(u, v, w);
	}

	int src = 0;
	std::vector<int> dist(n, INT_MAX);
	std::set<pair<int, int>> st;
	g.DijkstraAlgorithm(dist, st, src);

	// Print the distances
	std::cout << "Shortest distances from source " << src << " to all nodes:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "Node " << i << ": " << dist[i] << std::endl;
	}

	system("pause>0");

	return 0;
}
