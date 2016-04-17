#include <iostream>
#include <vector>

#include "bst.h"

using namespace std;


int main()
{
    cout << "it works" << endl;

    vector <int> numbers = {0, 1, 2, 3};
    for (auto num : numbers)
    {
    	cout << num << endl; 
    }

    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(8);
    bst.insert(1);

    bst.inorder();

    return 0;
}