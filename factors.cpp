#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

void getFactors(int N, vector<int>& factors) 
{
	for (int i = 2; i <= sqrt(N); i++) 
	{
		if (N % i == 0) 
		{
			factors.push_back(i); 
			factors.push_back(N/i); 
		}
	}
}

int main() 
{
	int N = 4; 

	vector<int> factors; 

	getFactors(N, factors);

	for (auto factor : factors) 
	{
		cout << factor << " "; 
	} 
	cout << endl; 
	return 0; 
}