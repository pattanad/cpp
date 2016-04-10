#include <iostream>
#include <vector>
#include <set>

using namespace std; 

class Edge {
public:
	Edge(int x, int y, int wt) : u(x), v(y), w(wt)
	{
	}
	~Edge() {}

	int either() {
		return u; 
	}

	int other(int x) {
		return (x == u)? v : u;  
	}

	int getWeight() {
		return w; 
	}

	void printEdge() {
		cout << u << " - " << v << "(" << w << ")" << endl; 
	}

private:
	int u; 
	int v; 
	int w; 
};

class EdgeWeightedGraph {
public:
	EdgeWeightedGraph(int N) : V(N), adjLists(N)
	{
	}

	~EdgeWeightedGraph() {}

	void addEdge(Edge* edge) {
		int u = edge->either(); 
		int v = edge->other(u); 
		cout << "Adding edge : " ; 
		edge->printEdge(); 
		adjLists[u].push_back(edge); 
		adjLists[v].push_back(edge);  
		edges.push_back(edge);
	}

	vector<Edge*> getAdjList(int u) {
		return adjLists[u]; 
	}

	vector<Edge*>& getEdges() {
		return edges; 
	}

	int getSize() {
		return V; 
	}

private:
	int V; 
	vector<vector<Edge*>> adjLists;
	vector<Edge*> edges;  
};

class MinPQ {
public:
	MinPQ() {}
	~MinPQ() {}

	void push(Edge* edge) {
		minheap.push_back(edge); 
		upheap(minheap.size()-1); 	
	} 

	Edge* getMin() {
		if (!empty()) {
			return minheap[0]; 
		}
		return nullptr; 
	} 

	void pop() {
		if (!empty()) {
			swap(minheap[0], minheap[minheap.size() - 1]); 
			minheap.pop_back(); 
			downheap(0); 
		}
	}

	bool empty() {
		return minheap.empty(); 
	}

private:
	int parent(int index) {
		if (index > 0) {
			return (index - 1)/2; 
		}
		return -1; 
	}

	int left(int index) {
		if (2*index + 1 < minheap.size()) {
			return 2*index + 1; 
		}
		return -1; 
	}

	int right(int index) {
		if (2*index + 2 < minheap.size()) {
			return 2*index + 2; 
		}
		return -1; 
	}

	void upheap(int index) {
		int p = parent(index); 

		while (p != -1) {
			if (minheap[index]->getWeight() < minheap[p]->getWeight()) {
				swap(minheap[index], minheap[p]);
				index = p; 
				p = parent(index); 
			}
			else {
				break; 
			}
		}
	}

	void downheap(int index) {
		int l = left(index); 
		int r = right(index); 

		while (l != -1 || r != -1) {
			if (r != -1) {
				// Both the children are present. 
				int min_index = (minheap[l]->getWeight() < minheap[r]->getWeight()) ? l : r; 
				if (minheap[min_index]->getWeight() < minheap[index]->getWeight()) {
					swap(minheap[index], minheap[min_index]); 
					index = min_index; 
				}
				else {
					break; 
				}
			}
			else {
				if (minheap[l]->getWeight() < minheap[index]->getWeight()) {
					swap(minheap[index], minheap[l]); 
					index = l; 
				}
				else {
					break; 
				}
			}
			l = left(index); 
			r = right(index); 
		}
	}
private:
	vector<Edge*> minheap; 
};

class UF {
public:
	UF(int N) : id(N), sz(N) {
		for(int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1; 
		}
	}

	bool connected(int u, int v) {
		return root(u) == root(v); 
	}

	void connect(int u, int v) {
		int x = root(u); 
		int y = root(v); 

		if (sz[x] > sz[y]) {
			id[y] = x; 
			sz[x] += sz[y];
		}
		else {
			id[x] = y; 
			sz[y] += sz[x]; 
		}
	}

private:
	int root(int u) {
		while (u != id[u]) {
			u = id[u]; 
		}
		return u; 
	}

private:
	vector<int> id; 
	vector<int> sz; 
};

class Kruskal {
public:
	Kruskal(EdgeWeightedGraph& graph) {
		MinPQ pq; 
		// Prepare the min pq with all the edges. 
		cout << "Building the Kruskal Algorithm" << endl; 
		for (auto edge: graph.getEdges()) {
			cout << "Inserting Edge into PQ:  " ; 
			edge->printEdge(); 
			pq.push(edge); 
		}

		UF uf(graph.getSize());  

		while (!pq.empty()) {
			Edge* edge = pq.getMin(); 
			pq.pop(); 
			int u = edge->either(); 
			int v = edge->other(u); 
			cout << "Processing Edge : " ; 
			edge->printEdge(); 
			if (!uf.connected(u, v)) {
				edges.push_back(edge); 
				cout << "Inserting edge : " ; 
				edge->printEdge(); 
				uf.connect(u, v);  
			}
		}
	}

	~Kruskal() {}

	vector<Edge*>& getEdges() {
		return edges; 
	}
private:
	vector<Edge*> edges;
};

int main() {
	int N = 8; 
	EdgeWeightedGraph graph(N);

	graph.addEdge(new Edge(0, 7, 16));  
	graph.addEdge(new Edge(2, 3, 17));  
	graph.addEdge(new Edge(1, 7, 19));  
	graph.addEdge(new Edge(0, 2, 26));  
	graph.addEdge(new Edge(5, 7, 28));  
	graph.addEdge(new Edge(1, 3, 29));  
	graph.addEdge(new Edge(1, 5, 32));  
	graph.addEdge(new Edge(2, 7, 34));  
	graph.addEdge(new Edge(4, 5, 35));  
	graph.addEdge(new Edge(1, 2, 36));  
	graph.addEdge(new Edge(4, 7, 37));  
	graph.addEdge(new Edge(0, 4, 38));  
	graph.addEdge(new Edge(6, 2, 40));  
	graph.addEdge(new Edge(3, 6, 52));  
	graph.addEdge(new Edge(6, 0, 58));  
	graph.addEdge(new Edge(6, 4, 93));  

	Kruskal kgraph(graph); 

	for (auto edge : kgraph.getEdges()) {
		edge->printEdge();  
	}

	return 0; 
}