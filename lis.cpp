#include <iostream>
#include <vector>

using namespace std; 

int lis(vector<int>& v)
{
	int lis[v.size()]; 

	for (int i = 0; i < v.size(); i++)
	{
		lis[i] = 1; 
	}

	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((v[i] > v[j]) && (lis[i] < lis[j] + 1))
			{
				lis[i] = lis[j] + 1; 
			}
		}
	}

	int max = 0; 

	for (int i = 0; i < v.size(); i++)
	{
		if (max < lis[i])
		{
			max = lis[i]; 
		}
	}
	return max; 
}

int main()
{
	std::vector<int> v = {10, 22, 9, 33, 21, 50, 41, 60};

	for (auto num : v)
	{
		cout << num << " " ;
	}
	cout << endl;

	int result = lis(v);

	cout << "LIS: " << result << endl; 
	
	return 0;
}
