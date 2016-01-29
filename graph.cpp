#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef pair<int, int> EDGE; 

enum STATE {
	NOT_VISITED = 0,
	TRANSIENT, 
	VISITED
};

class Node
{
public: 
	Node(int data_): data(data_), visited(NOT_VISITED)
	{
	}

	Node():visited(NOT_VISITED)
	{
	}

	~Node() 
	{
	}

	Node& operator=(const Node& node)
	{
		if (this != &node)
		{
			data = node.data; 
			neighbors = node.neighbors; 
		}
		return *this;
	}

	int data;
	int visited; 
	vector<Node*> neighbors; 
};



class Graph {
public:
	Graph(std::vector<EDGE>& edges)
	{
		for(auto edge: edges)
		{	
			addEdge(edge);  
		}
	}

	void printGraph()
	{
		for (auto vertex : vertices)
		{
			cout << vertex->data << " : " ; 
			for (auto neighbor : vertex->neighbors)
			{
				cout << neighbor->data << " "; 
			}
			cout << endl; 
		}
	}

	void BFS(int data)
	{
		cout << "Performing BFS on graph" << endl; 
		Node* node = getNode(data);

		queue<Node*> bfs_queue; 

		node->visited = VISITED;

		bfs_queue.push(node);

		while (!bfs_queue.empty())
		{
			Node* vertex =  bfs_queue.front();
			bfs_queue.pop(); 
			cout << "Node Visited : " << vertex->data << endl; 
			
			for (auto v : vertex->neighbors)
			{
				if (v->visited == NOT_VISITED)
				{
					// This node has not been visited, So mark it as visited and add the neighbors to the queue.
					v->visited = VISITED;
					bfs_queue.push(v); 
				}
			}
		} 
	}

	void DFS(Node* vertex)
	{
		vertex->visited = VISITED; 
		cout << "NDOE Visited : " << vertex->data << endl; 

		for (auto v : vertex->neighbors)
		{
			if (v->visited == NOT_VISITED)
			{
				v->visited = TRANSIENT; 
				DFS(v); 
			}
			v->visited = VISITED; 
		}
	}

	void DFS()
	{
		cout << "Performing DFS on theh graph" << endl; 
		for (auto vertex : vertices)
		{
			if (vertex->visited == NOT_VISITED)
			{
				DFS(vertex);
			}
		}
	}

	void reset()
	{
		for (auto vertex : vertices)
		{
			vertex->visited = NOT_VISITED; 
		}
	}

protected: 
	bool addEdge(EDGE& e)
	{
		Node* v1 = getNode(e.first); 
		if (v1 == nullptr)
		{
			// The node does not exist in the graph. So add it. 
			v1 = new Node(e.first); 
			vertices.push_back(v1); 
		}

		Node* v2 = getNode(e.second); 
		if (v2 == nullptr)
		{
			v2 = new Node(e.second);
			vertices.push_back(v2);
		}

		// This is an undirected graph. 
		v1->neighbors.push_back(v2); 
		v2->neighbors.push_back(v1);
	}

	Node* getNode(int data)
	{
		for (auto vertex : vertices)
		{
			if (vertex->data == data)
			{
				return vertex; 
			}
		}
		return nullptr;
	}

private: 
	vector<Node*> vertices;
};


int main()
{
	cout << "Graph problem : " << endl ; 
	vector<EDGE> edges; 
	EDGE e1 = {1, 2};
	edges.push_back(e1); 
	EDGE e2 = {2, 4};
	edges.push_back(e2); 
	EDGE e3 = {1, 3};
	edges.push_back(e3); 
	EDGE e4 = {3, 4};
	edges.push_back(e4); 

	Graph g(edges); 

	g.printGraph(); 

	g.BFS(1); 

	g.reset();
	g.DFS(); 

	return 0; 
}