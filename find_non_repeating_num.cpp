// This program implements the problem :  http://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/

#include <iostream>
#include <vector>

using namespace std; 

void findNonRepeatingNums(std::vector<int>& v, int& num1, int& num2)
{
	int xor_all = 0; 

	for (auto num: v)
	{
		xor_all ^= num; 
	}

	// once we have the xor of all the numbers, we need to find any set bit. 
	// To find rightmost set bit we use the technique n & ~(n-1). 

	int set_bit = xor_all & ~(xor_all - 1); 

	// Now we go through the set of numbers again and divide the numbers into 
	// two groups. One with the bit set and one without the bit set. 

	for (auto num: v)
	{
		if (set_bit & num)
		{
			num1 ^= num; 
		}
		else 
		{
			num2 ^= num; 
		}
	}
}

int main()
{
	std::vector<int> v = {2, 4, 7, 9, 2, 4};

	int num1 = 0, num2 = 0; 
	findNonRepeatingNums(v, num1, num2); 

	cout << "The numbers are " << num1 << " and " << num2 << endl; 
	return 0;
}