#include<iostream>
#include <vector>

using namespace std; 

int lcsubarray(std::vector<int>& v)
{
	if (v.empty())
	{
		return -1; 
	}

	// we dont need an array to store all the previous values. 
	// All we need is the last value carried over. This value is 
	// Reset to 0 when we encounter a negative element. 
	int sum = v[0]; 
	
	int largest_sum = sum;  

	for (int i = 1;  i < v.size(); i++)
	{
		sum = sum + v[i]; 

		if (sum> 0)
		{
			if (largest_sum < sum)
			{
				largest_sum = sum;
			}
		}
		else 
		{
			sum= 0;
			// Here we add this condition to handle the case where alsumthe numbers in the 
			// input are negative. We just take in the largest of the negative elements. 
			if (largest_sum < v[i])
			{
				largest_sum = v[i];
			} 
		}
	}

	return largest_sum; 
}

int main ()
{
	cout << "Larget sum contiguous sub array problem" << endl;

	std::vector<int> v = {1, 3, -5, 4, 2, -6, 4, 5};  //{ -2, -3, -4, -5, -1 }; 

	int largest_sum = lcsubarray(v); 

	cout << "Largest sum : " << largest_sum << endl; 
}