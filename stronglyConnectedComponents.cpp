#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class DiGraph {
public:
	DiGraph(int N, vector<pair<int,int>>& edges) : V(N), adjLists(N), revAdjLists(N)
	{
		for (auto edge : edges) { 
			adjLists[edge.first].push_back(edge.second); 
			revAdjLists[edge.second].push_back(edge.first); 
		}
	}
	~DiGraph() {}

	int size() {
		return V; 
	}

	vector<int>& getAdjList(int n) {
		return adjLists[n]; 
	}

	vector<int>& getRevAdjList(int n) {
		return revAdjLists[n]; 
	}

private:
	int V; 
	vector<vector<int>> adjLists;
	vector<vector<int>> revAdjLists; 
};

class TopologicalSort {
public:
	TopologicalSort(DiGraph& graph, bool reverse) : dag(graph), visited(graph.size()), rev(reverse) {
		for (int i = 0; i < dag.size(); i++) {
			visited[i] = false; 
		}

		for (int i = 0; i < dag.size(); i++) {
			if (!visited[i]) {
				dfs(i); 
			}
		}
	}

	~TopologicalSort()  {}

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
		auto adjList = dag.getAdjList(n); 

		if (rev) {
			adjList = dag.getRevAdjList(n); 
		} 

		for (auto v : adjList) {
			if (!visited[v]) {
				dfs(v); 
			}
		}
		reversePostOrder.push(n); 
	}
private:
	DiGraph& dag; 
	stack<int> reversePostOrder; 
	vector<bool> visited;
	bool rev;  
};

class SCC {
public:
	SCC(DiGraph& graph) : dag(graph), id(graph.size()), visited(graph.size()), count(0)
	{
		for (int i = 0; i < dag.size(); i++) {
			id[i] = 0; 
			visited[i] = false; 
		}

		TopologicalSort tsort(dag, true);

		vector<int> order = tsort.getOrder(); 

		for (auto n : order) {
			if (!visited[n]) {
				dfs(n, count); 
				count++; 
			}
		}  
	}
	~SCC() {}

	bool connected(int u, int v) {
		return id[u] == id[v]; 
	}

	void printId () {
		for (auto n : id) {
			cout << n << " "; 
		}
		cout << endl; 
	}

	int getCount() {
		return count; 
	}

private:
	void dfs(int n, int c) {
		visited[n] = true; 
		id[n] = c; 

		for (auto v : dag.getAdjList(n)) {
			if (!visited[v]) {
				dfs(v, c); 
			}
		}
	}

private:
	DiGraph& dag; 
	vector<int> id; 
	vector<int> visited; 
	int count; 
};


int main() {
	int N = 13; 

	vector<pair<int, int>> edges; 

	edges.push_back(make_pair(0,1));
	edges.push_back(make_pair(0,5));
	edges.push_back(make_pair(2,0));
	edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(3,2));
	edges.push_back(make_pair(3,5));
	edges.push_back(make_pair(4,2));
	edges.push_back(make_pair(4,3));
	edges.push_back(make_pair(5,4));
	edges.push_back(make_pair(6,0));
	edges.push_back(make_pair(6,4));
	edges.push_back(make_pair(6,9));
	edges.push_back(make_pair(6,8));
	edges.push_back(make_pair(7,6));
	edges.push_back(make_pair(7,9));
	edges.push_back(make_pair(8,6));
	edges.push_back(make_pair(9,10));
	edges.push_back(make_pair(9,11));
	edges.push_back(make_pair(10,12));
	edges.push_back(make_pair(11,4));
	edges.push_back(make_pair(11,12));
	edges.push_back(make_pair(12,9));

	DiGraph graph(N, edges); 

	SCC scc(graph); 

	scc.printId(); 
	cout << "Number of SCC : " << scc.getCount() << endl; 
	
	return 0;
}