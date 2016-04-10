#include <iostream>
#include <vector>


using namespace std; 

class Graph {
public: 

	Graph(int N, vector<pair<int, int>>& edges) : V(N), adjList(N) // Initialize the adjList with size N. 
	{
		for (auto edge : edges) {
			// Build up the links. 
			adjList[edge.first - 1].push_back(edge.second - 1); 
			adjList[edge.second - 1].push_back(edge.first - 1); 
		}
	}
	~Graph() {}

	int size() {
		return V; 
	}

	bool getAdjList(int n, vector<int>& aList) {
		if (n < V) {
			aList = adjList[n]; 
			return true; 
		}
		return false; 
	}

private:
	int V; 
	vector<vector<int>> adjList; 
};

class CComponents {
public: 
	CComponents(Graph& g) : graph(g), id(graph.size()), marked(graph.size()), count(0)
	{
		for (int i = 0; i < graph.size(); i++) {
			id[i] = 0; 
			marked[i] = false; 
		}

		for (int i = 0; i < graph.size(); i++) {
			if (!marked[i]) {
				dfs(i, count); 
				count++; 
			}
		}
	}
	~CComponents() {}

	int getCount() {
		return count; 
	}

	bool connected(int u, int v) {
		return id[u-1] == id[v-1]; 
	}

	void printId() {
		for (auto i : id) {
			cout << i << " ";
		}
		cout << endl; 
	}

private:
	void dfs(int n, int c) {
		marked[n] = true; 
		id[n] = c; 
		vector<int> adjList; 
		if (graph.getAdjList(n, adjList)) {
			for (auto v : adjList) {
				if (!marked[v]) {
					dfs(v, c); 
				}
			}
		} 
	}	

private:
	Graph& graph; 
	vector<int> id; 
	vector<bool> marked;
	int count;  
};


int main () {
	int N = 5; 
	vector<pair<int, int>> edges; 
	edges.push_back(make_pair(1,2));
	edges.push_back(make_pair(1,3));
	edges.push_back(make_pair(2,4));
	edges.push_back(make_pair(3,4));

	Graph g(N, edges); // construct the graph. 

	CComponents ccomp(g); 

	cout << "Number of connected components : " << ccomp.getCount() << endl; 

	cout << "is 1 & 2 connected? : " << ccomp.connected(1, 2) << endl ; 
	cout << "is 1 & 3 connected? : " << ccomp.connected(1, 3) << endl;  
	cout << "is 1 & 4 connected? : " << ccomp.connected(1, 4) << endl; 
	cout << "is 1 & 5 connected? : " << ccomp.connected(1, 5) << endl ; 
	

	ccomp.printId(); 

	return 0; 
}