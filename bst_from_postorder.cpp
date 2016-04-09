#include <iostream>
#include <climits>

using namespace std; 

struct node {
	int data; 
	node* left; 
	node* right; 

	node(int d) : data(d), left(nullptr), right(nullptr) {}
	node() : data(0), left(nullptr), right(nullptr) {}
	~node() {}
};

node* constructTreeUtil(int* arr, int& post_index, int min, int max, int size) {
	if (post_index < 0) {
		return nullptr; 
	}

	node* root = nullptr; 
	if (arr[post_index] < max && arr[post_index] > min) {
		root = new node(arr[post_index]); 
		post_index -= 1; 

		if (post_index >= 0) {
			root->right = constructTreeUtil(arr, post_index, root->data, max, size); 
			root->left = constructTreeUtil(arr, post_index, min, root->data, size); 			
		}
	}
	return root; 
} 

node* constructTree(int* arr, int size) {
	int post_index = size - 1; 
	return constructTreeUtil(arr, post_index, INT_MIN, INT_MAX, size); 
}

void printInorder(node* root) {
	if (root == nullptr) {
		return;
	}
	printInorder(root->left); 
	cout << root->data << " "; 
	printInorder(root->right); 
}
// Driver program to test above functions
int main ()
{
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof( post ) / sizeof( post[0] );
 
    node *root = constructTree(post, size);
 
    cout << "Inorder traversal of the constructed tree:" << endl;
    printInorder(root);
    cout << endl; 
 
    return 0;
}