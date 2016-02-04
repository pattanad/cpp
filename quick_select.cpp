#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(std::vector<int>& v, int start, int end)
{
	cout << "Partition : start index : " << start << " End index : " << end << endl; 
	for (int i = start; i <= end; i++)
	{
		cout << v[i] << " " ; 
	}
	cout << endl; 

	int pivot = v[end]; 

	int partition_index = start; 
	for (int i = start; i < end; i++)
	{
		if (v[i] < pivot)
		{
			swap(v[i], v[partition_index]); 
			partition_index++; 
		}
	}
	swap(v[end], v[partition_index]);

	cout << "Partitioned array : " << endl; 
	for (int i = start; i <= end; i++)
	{
		cout << v[i] << " " ; 
	} 
	cout << endl;
	return partition_index; 
} 

int quickSelect(std::vector<int>& v, int start, int end, int n)
{
	if (start >= end) 
	{
		cout << "Returning from quickSelect" << endl; 
		return -1; 
	}

	int index = partition(v, start, end);

	cout << "Index returned : " << index << " Required n : " << n << endl; 
	if (index+1 == n)
	{
		return v[index]; 
	} 
	if (index+1 > n)
	{
		return quickSelect(v, start, index-1, n); 
	}
	else 
	{
		return quickSelect(v, index+1, end, n); 
	}
}

int main()
{
	std::vector<int> v = {4, 2, 7, 9, 5, 1, 3, 8, 6};

	std::vector<int> v2 = v;

	cout << "Original Array : " << endl; 
	for (auto num: v)
	{
		cout << num << " " ; 
	}
	cout << endl; 

	cout << "Original sorted array " << endl ; 

	sort(begin(v), end(v)); 

	for (auto num : v)
	{
		cout << num << " "; 
	}
	cout << endl; 

	int n = 9; 
	int nth_value = quickSelect(v2, 0, v2.size()-1, n);

	cout << n << " value : " << nth_value << endl;  
	return 0; 
}