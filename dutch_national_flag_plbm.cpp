#include <iostream>
#include <vector>

using namespace std; 


void dnf(vector<int>& input)
{
	// The logic to to partition the array into 4 parts. 
	// input[0 - (Low - 1)] -- 0
	// input[Low - (Mid - 1)] -- 1
	// input[Mid - (High - 1)] -- unknown
	// input[High - (N-1)] -- 2

	int low = 0, mid = 0, high = input.size() - 1; 

	while (mid <= high)
	{
		if (input[mid] == 0)
		{
			swap(input[mid], input[low]);
			mid++; 
			low++; 
		}
		else if (input[mid] == 1)
		{
			mid++;
		}
		else if (input[mid] == 2)
		{
			swap(input[mid], input[high]); 
			// Here we just decrement high and do not increment mid (as we had done in case 0)
			// Because we would have to trickle down the value to its lowest possible state. 
			// Say if there was a 0, then we swap input[mid] with input[high] but we also need
			// to trickle down the 0 to low. Else the state would not be proper. 
			high--; 
		}
	}
	return; 
}

int main ()
{
	vector<int> a = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

	for (auto i : a)
	{
		cout << i << " "; 
	}
	cout << endl; 

	dnf(a); 

	for (auto i : a)
	{
		cout << i << " " ;
	}
	cout << endl; 
	return 0; 
}
