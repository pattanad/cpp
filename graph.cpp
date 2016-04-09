#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <climits>

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
	Node(int data_): data(data_), visited(NOT_VISITED), parent(nullptr), distance(0)
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
			data      = node.data; 
			parent    = node.parent; 
			distance  = node.distance; 
			neighbors = node.neighbors; 
		}
		return *this;
	}

	int data;
	int visited;
	Node* parent;  
	int distance; 
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
		cout << "NODE Visited : " << vertex->data << endl; 

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
			vertex->distance = INT_MAX; 
			vertex->parent = nullptr;  
		}
	}

	bool pathBetweenTwoNodes(int d1, int d2)
	{
		Node* node1 = getNode(d1); 
		Node* node2 = getNode(d2);

		return pathBetweenTwoNodes(node1, node2);
	}

/* Performing BFS in the graph starting node1 to find node2. */
	bool pathBetweenTwoNodes(Node* node1, Node* node2)
	{
		queue<Node*> my_queue; 

		node1->visited = VISITED; 

		my_queue.push(node1); 

		while (!my_queue.empty())
		{
			Node* n = my_queue.front();
			my_queue.pop();

			if (n->data == node2->data)
			{
				cout << "Path exists between the nodes " << node1->data << " and " << node2->data << endl; 
				return true; 
			}
			n->visited = VISITED; 

			for (auto v : n->neighbors)
			{
				if (v->visited == NOT_VISITED)
				{
					my_queue.push(v);
				}
			}
		}
		return false; 
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

	g.reset(); 

	if (g.pathBetweenTwoNodes(1,2))
	{
		cout << "Path between nodes 1 and 2 exist" << endl; 
	} 
	else 
	{
		cout << "Path does not exist" << endl; 
	}

	return 0; 
}