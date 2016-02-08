#include <iostream>
#include <vector>

using namespace std; 

bool pivot_search(const std::vector<int>& v, int num, int start, int end)
{
	if (start > end)
	{
		return false; 
	}

	int mid = (start + end)/2; 

	if (v[mid] == num)
	{
		return true; 
	}

	if (v[start] < v[mid]) // left is normally ordered. 
	{	
		if (num >= v[start] && num < v[mid])
		{
			// The element is within this range. 
			return pivot_search(v, num, start, mid-1); 
		}
		else 
		{
			return pivot_search(v, num, mid+1, end); 
		}
	}
	else // The right is normally ordered. 
 	{
 		if (num > v[mid] && num <= v[end])
 		{
 			return pivot_search(v, num, mid+1, end);
 		}
 		else 
 		{
 			return pivot_search(v, num, start, mid-1); 
 		}
	}
}

bool pivot_search(const std::vector<int>& v, int num)
{
	return pivot_search(v, num, 0, v.size()-1); 
}

int main()
{
	std::vector<int> v = {3, 4, 5, 1, 2};

	if (pivot_search(v, 2))
	{
		cout << "Element found" << endl; 
	}
	else 
	{
		cout << "Element not found" << endl; 
	}
	return 0;
}