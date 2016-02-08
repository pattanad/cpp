#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <climits>

#include "bst.h"

using namespace std; 

BT::BT():root(nullptr)
{
}

BT::~BT()
{
	// Need to delete the nodes before we destruct.
	if (root != nullptr)
	{
		queue<Node*> delete_queue; 

		delete_queue.push(root); 

		while (!delete_queue.empty())
		{
			Node* node = delete_queue.front(); 
			delete_queue.pop(); 

			if (node->left != nullptr) 
			{
				delete_queue.push(node->left); 
			}
			if (node->right != nullptr)
			{
				delete_queue.push(node->right); 
			}

			// cout << "Deleting node : " << node->data << endl; 

			delete node; 
			node = nullptr; 
		}
	}
}

void BT::setRoot(int data)
{
	root = new Node(data); 
}

Node* BT::getRoot()
{
	return root; 
}

bool BT::isBST(Node* node, int min, int max)
{
	if (node == nullptr)
	{
		return true; 
	}

	if (node->data < min || node->data > max)
	{
		return false; 
	}
	
	if (!isBST(node->left, min, node->data) || !isBST(node->right, node->data, max))
	{cout << "Node : " << node->data << " Returning false" << endl;
		return false;
	}   
	return true; 
}

bool BT::isBST()
{
	return isBST(root, INT_MIN, INT_MAX); 
}

BST::BST()
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
	cout << node->data << " "; 
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

	cout << node->data << " "; 
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

	cout << node->data << " "; 
}

bool BST::isBalanced()
{
	int height; 
	isBalanced(root, height);
}

bool BST::isBalanced(Node* node, int& height)
{
	if (node == nullptr)
	{
		height = 0;
		return true;  
	}

	int l_height, r_height; 

	if (isBalanced(node->left, l_height) && isBalanced(node->right, r_height))
	{
		height = max(l_height, r_height) + 1;

		if (abs(l_height - r_height) > 1)
		{
			return false;
		}
		else 
		{ 
			return true;
		} 
	}
	else
	{
		return false; 
	}
}

void BST::createLinkedListAtEachDepth(Node* node, vector<vector<int>>& lists, int level)
{
	if (node == nullptr)
	{
		return; 
	}

	if (lists.size() == level)
	{
		// This level has not been parsed. So create a new list and push into the lists. 
		vector<int> list; 
		list.push_back(node->data); 
		lists.push_back(list); 
	}
	else 
	{
		lists[level].push_back(node->data); 
	}

	createLinkedListAtEachDepth(node->left, lists, level+1);
	createLinkedListAtEachDepth(node->right, lists, level+1);
}

void BST::createLinkedListAtEachDepth(vector<vector<int>>& lists)
{
	int level = 0; 
	createLinkedListAtEachDepth(root, lists, level); 
}

Node* BST::getNode(int data, Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	} 

	if (data == node->data)
	{
		return node;
	}

	else if (data > node->data)
	{
		return getNode(data, node->right);
	}
	else 
	{
		return getNode(data, node->left); 
	}
}

Node* BST::getMinNode(Node* node)
{
	if (node != nullptr)
	{
		while (node->left != nullptr)
		{
			node = node->left; 
		}
		return node; 
	}
	return nullptr; 
}

int BST::inOrderSuccessor(int data)
{
	Node* node = getNode(data, root); 

	if (node != nullptr)
	{
		// Node found. Process the inorder. 
		if (node->right != nullptr)
		{
			Node* minNode = getMinNode(node->right);
			return minNode->data; 
		}
		else 
		{
			// The successor will be one of the parents as the right subtree does not exist. 
			Node* parent = node->parent; 
			while (parent != nullptr && node != node->parent->left)
			{
				node = parent; 
				parent = node->parent; 
			}

			if (parent != nullptr)
			{
				return parent->data;
			}
			else 
			{
				return -1; // this is supposed to be the error code. 
			}
		}
	}
	else 
	{
		return -1; 
	}
}

bool BST::contains(Node* node1, Node* node2)
{
	if (node1 == nullptr || node2 == nullptr)
	{
		return false; 
	}

	if (node1->data == node2->data)
	{
		return true; 
	}

	return contains(node1->left, node2) || contains(node1->right, node2); 
}

int BST::lca(int data1, int data2)
{
	Node* node1 = getNode(data1, root); 
	Node* node2 = getNode(data2, root); 

	if (node1 == nullptr || node2 == nullptr)
	{
		return -1; 
	}

	if (node1 == root) 
	{
		return node1->data; 
	}
	if (node2 == root)
	{
		return node2->data;
	}

	while (node1 != nullptr)
	{
		if (contains(node1, node2))
		{
			cout << node1->data << " contains " << node2->data << endl; 
			return node1->data; 
		}
		else
		{
			node1 = node1->parent; 
		}
	}
	return -1; 
}

void createBalancedBinTree(std::vector<int>& v, int start, int end, BST& bst)
{
	if (start > end)
	{
		return; 
	}

	int mid = (start + end)/2; 
	bst.insert(v[mid]); 
	createBalancedBinTree(v, start, mid-1, bst); 
	createBalancedBinTree(v, mid+1, end, bst);
}

bool isBTaBST(BT& btree)
{
	return btree.isBST(); 
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
    bst.insert(9);
    bst.insert(10);

    cout << "BST Inorder" << endl; 
    bst.inorder();
    cout << endl; 

    cout << "BST Preorder" << endl;
    bst.preorder();
    cout << endl; 

    cout << "BST Postorder" << endl; 
    bst.postorder();
    cout << endl; 

    cout << "BST Balance computation -- BEGIN" << endl; 
    if (bst.isBalanced())
    {
    	cout << "BST is balanced" << endl; 
    }
    else
    {
    	cout << "BST is not balanced" << endl;
    }
    cout << "BST Balance computation -- END" << endl;

    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    for (auto i : v)
    {
    	cout << i << " "; 
    }
    cout << endl; 

    cout << "Problem to create balanced binary tree from a sorted array --- BEGIN" << endl ; 
    BST bstree;
    
    createBalancedBinTree(v, 0, v.size() - 1, bstree);

    if(bstree.isBalanced())
    {
    	cout << "Tree is balanced" << endl; 
    }
    else 
    {
    	cout << "Tree is not balanced" << endl; 
    }
	cout << "Problem to create balanced binary tree from a sorted array --- END" << endl ; 

    // Plbm 4.4 of cracking the coding interview : Create linked list of each depth.
    cout << "Create Linked list at each level of Binary tree -- BEGIN" << endl;
    vector<vector<int>> lists; 
    bst.createLinkedListAtEachDepth(lists); 

// Printing the lists.  
    for (auto list : lists)
    {
    	for (auto i : list) 
    	{
    		cout << i << " ";
    	}
    	cout << endl; 
    } 
    cout << "Create Linked list at each level of Binary tree -- END" << endl ; 

    cout << "Is binary tree a binarry search tree ? -- BEGIN" << endl; 

    BT btree; 
    btree.setRoot(10); 
    Node* node = btree.getRoot(); 

    node->left = new Node(5); 
    node->right = new Node(15); 
    node->left->right = new Node(7); 
    node->left->left = new Node(3); 
    node->right->right = new Node(17); 
    node->right->left = new Node(19); 

    if (isBTaBST(btree))
    {
    	cout << "This is BST" << endl ; 
    } 
    else 
    {
    	cout << "This is not a BST" << endl; 
    }
    cout << "Is binary tree a binarry search tree ? -- END" << endl; 

    cout << "Inorder successor in a BST -- BEGIN" << endl; 
    int num = 10; 
    cout << "Inorder successor of " << num << " is : " << bst.inOrderSuccessor(num) << endl; 

    cout << "Inorder successor in a BST -- END" << endl;

    cout << "Lowest common ancestor computation -- BEGIN" << endl; 

    int data1 = 5, data2 = 11; 
    int data = bst.lca(data1, data2);  
    cout << "LCA of " << data1 << " and " << data2 << " is " << data << endl; 

    cout << "Lowest common ancestor computation -- END" << endl; 

    return 0;
}