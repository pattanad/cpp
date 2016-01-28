#include <iostream>
#include <vector>

#include "bst.h"

using namespace std; 

BST::BST():root(nullptr)
{
}

BST::~BST()
{
}

void BST::insert(int data)
{
	insert(data, root, nullptr); 
}

Node* BST::insert(int data, Node* node, Node* parent)
{
	if (node == nullptr)
	{
		Node* newNode = new Node(data); 
		if (root == nullptr)
		{
			root = newNode; 
		}
		node = newNode; 
		node->parent = parent; 
		return node; 
	}

	if (data > node->data)
	{
		node->right = insert(data, node->right, node);
	}
	else 
	{
		node->left = insert(data, node->left, node);
	}
	return node; 
}

void BST::inorder()
{
	inorder(root);
}

void BST::inorder(Node* node)
{
	if (node == nullptr)
	{
		return; 
	}

	inorder(node->left); 
	cout << node->data << endl; 
	inorder(node->right);
}

void BST::preorder()
{
	preorder(root);
}

void BST::preorder(Node* node)
{
	if (node == nullptr)
	{
		return; 
	}

	cout << node->data << endl; 
	preorder(node->left);
	preorder(node->right);
}

void BST::postorder()
{
	postorder(root);
}

void BST::postorder(Node* node)
{
	if (node == nullptr)
	{
		return; 
	}

	postorder(node->left);
	postorder(node->right);

	cout << node->data << endl; 
}

int main()
{
    cout << "it works" << endl;

    vector <int> numbers = {0, 1, 2, 3};
    for (auto num : numbers)
    {
    	cout << num << " " ; 
    }
    cout << endl; 

    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);

    cout << "BST Inorder" << endl; 
    bst.inorder();

    cout << "BST Preorder" << endl;
    bst.preorder();

    cout << "BST Postorder" << endl; 
    bst.postorder();

    return 0;
}