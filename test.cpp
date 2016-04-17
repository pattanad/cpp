#include <iostream>
#include <vector>

using namespace std; 

void printString(string& myString) 
{
	if (!myString.empty()) 
	{
		cout << myString << endl; 
	}
}


int main ()
{
	/* this is a c++11 testcode*/
	vector<int> myVec = { 0, 1, 3, 4, 5 }; 

	for (auto i : myVec)
	{
		cout << i << " ";
	}
	cout << endl; 

	//int* p = (int *)0xffffabcd; 

	//*p = 5; 

	//cout << *p << endl; 

	char* str = nullptr; 

	printString(string(str)); 
	return 0;
}



