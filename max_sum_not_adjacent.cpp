// this problem implements the problem : http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include <iostream>
#include <vector>

using namespace std;

// here we are solving this using Dynamic programming technique. the max sum S(i) 
// where i represents the length of the array depends on 2 factors : 
// S[i] = Max (S[i-1] --> excluding the current element v[i],
// 			 	S[i-2] + v[i] --> including the current element v[i]
int max_sum_non_adjacent(const std::vector<int>& v)
{
	int size = v.size(); 
	std::vector<int> s(size);

	s[0] = v[0]; 
	s[1] = v[1]; 

	for (int i = 2; i < size; i++)
	{
		s[i] = max(s[i-2] + v[i], s[i-1]);
	}
	return s[size - 1]; 
} 

int main()
{
	std::vector<int> v = {5, 5, 10, 40, 50, 35};

	int max_sum = max_sum_non_adjacent(v);

	cout << "Max sum is : " << max_sum << endl ; 

	return 0; 
}