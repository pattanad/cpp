#ifndef _BST_H_
#define _BST_H_
#include <iostream>

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

class BST
{
public:
	BST();
	~BST();
	void insert(int data);
	void inorder(); 
	void preorder();
	void postorder();

protected:
	Node* insert(int data, Node* node, Node* parent);
	void inorder(Node* node); 
	void preorder(Node* node);
	void postorder(Node* node);
	 
private: 
	Node* root; 
};


#endif