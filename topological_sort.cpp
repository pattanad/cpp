#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

// Topological sorting works only if the graph is a DAG (Directed Acyclic Graph)

class DiGraph {
public:
	DiGraph(int N, vector<pair<int, int>>& edges) : V(N), adjLists(N)  
	{
		for (auto edge : edges) {
			adjLists[edge.first].push_back(edge.second); 
		}
	}

	~DiGraph() {}

	int size() {
		return V; 
	}

	vector<int>& getAdjList(int n) {
		return adjLists[n]; 
	}

private:
	int V; // Number of vertices.  
	vector<vector<int>> adjLists;
};

class TopologicalSort {
public: 
	TopologicalSort(DiGraph& graph) : dag(graph), visited(graph.size()) {
		for (int i = 0; i < dag.size(); i++) {
			visited[i] = false; 
		}

		for (int i = 0; i < dag.size(); i++) {
			if (!visited[i]) {
				dfs(i); 
			}
		}
	}

	~TopologicalSort() {}

	vector<int> getOrder() {
		vector<int> result; 

		while (!reversePostOrder.empty()) {
			result.push_back(reversePostOrder.top()); 
			reversePostOrder.pop(); 
		}
		return result; 
	}

private:
	void dfs(int n) {
		visited[n] = true; 
		for (auto v : dag.getAdjList(n)) {
			if (!visited[v]) {
				dfs(v); 
			}
		}
		reversePostOrder.push(n); 
	}
private:
	DiGraph& dag; // creating a reference so that copy is avoided. 
	stack<int> reversePostOrder; 
	vector<bool> visited; 
};

int main () {
	int N = 7; 

	vector<pair<int, int>> edges; 

	edges.push_back(make_pair(0, 2)); 
	edges.push_back(make_pair(0, 5)); 
	edges.push_back(make_pair(0, 1)); 
	edges.push_back(make_pair(1, 4)); 
	edges.push_back(make_pair(5, 2)); 
	edges.push_back(make_pair(3, 2)); 
	edges.push_back(make_pair(3, 5)); 
	edges.push_back(make_pair(3, 6)); 
	edges.push_back(make_pair(3, 4)); 
	edges.push_back(make_pair(6, 4)); 
	edges.push_back(make_pair(6, 0)); 

	DiGraph dag(N, edges); 

	TopologicalSort tp(dag); 

	for (auto n : tp.getOrder()) {
		cout << n << " ";
	}
	cout << endl; 

	return 0; 
}