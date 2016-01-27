#include <iostream>
#include <vector>

using namespace std; 

int main ()
{
	vector<int> myVec = { 0, 1, 3, 4, 5 }; 

	for (auto i : myVec)
	{
		cout << i << " ";
	}
	cout << endl; 
	return 0;
}



