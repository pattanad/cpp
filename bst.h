#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include <vector>

class Node
{
public:
	Node(int data_): data(data_), left(nullptr), right(nullptr), parent(nullptr)
	{
	}
	~Node()
	{}

	int data; 
	Node* left; 
	Node* right;
	Node* parent;  
};

class BT
{
public: 
	BT(); 
	~BT(); 
	virtual bool isBST(); 

	void setRoot(int data); 
	Node* getRoot(); 

protected: 
	bool isBST(Node* root, int min, int max); 

protected:  
	Node* root; 
};

class BST : BT
{
public:
	BST();
	~BST();
	void insert(int data);
	void inorder(); 
	void preorder();
	void postorder();
	bool isBalanced();
	void createLinkedListAtEachDepth(std::vector<std::vector<int>>& lists);
	int inOrderSuccessor(int data); 

protected:
	Node* insert(int data, Node* node, Node* parent);
	void inorder(Node* node); 
	void preorder(Node* node);
	void postorder(Node* node);
	bool isBalanced(Node* node, int& height);
	void createLinkedListAtEachDepth(Node* node, std::vector<std::vector<int>>& lists, int level);
	Node*  getNode(int data, Node* node);
	Node* getMinNode(Node* node);  
};


#endif