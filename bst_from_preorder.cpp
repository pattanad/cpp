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

node* constructTreeUtil(int* arr, int& pre_index, int min, int max, int size) {
	if (pre_index >= size) {
		return nullptr; 
	}

	node* root = nullptr; 
	if (arr[pre_index] < max && arr[pre_index] > min) {
		root = new node(arr[pre_index]); 
		pre_index += 1; 

		if (pre_index < size) {
			root->left = constructTreeUtil(arr, pre_index, min, root->data, size); 			
			root->right = constructTreeUtil(arr, pre_index, root->data, max, size); 
		}
	}
	return root; 
} 

node* constructTree(int* arr, int size) {
	int pre_index = 0; 
	return constructTreeUtil(arr, pre_index, INT_MIN, INT_MAX, size); 
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
    int pre[] =  {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    node *root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree:" << endl;
    printInorder(root);
    cout << endl; 
 
    return 0;
}