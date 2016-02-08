#include <iostream>

using namespace std; 

void longestPalindromicSubstring(string& str, int& start_index, int& max_length)
{
	int n = str.size(); 

	int table[n][n]; 

	// Initialize the table. 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			table[i][j] = 0; 
		}
	}

	for (int i = 0; i < n; i++)
	{
		table[i][i] = 1;
		if (max_length < 1)
		{
			max_length = 1;
		}
	}

	for (int i = 0; i < n-1; i++)
	{
		if (str[i] == str[i+1])
		{
			table[i][i+1] = 2;
			if (max_length < 2)
			{
				max_length = 2; 
			} 
		}
	}
 
	// This is the lenght of the string we are looking into. 
	for (int l = 3; l <= n; l++)
	{
		// Her we parse the string upto length l and check for palindrome. 
		for (int i = 0; i < n - l + 1; i++)
		{
			// Set j to be the end of the string of length l. 
			int j = i + l - 1; 

			// cout << "i : " << i << " j : " << j << endl; 

			// If match found, then increment the count. 
			if (str[i] == str[j] && table[i+1][j-1] != 0)
			{
				// cout << " Match found : i :" << i << " j: " << j << " Length : " << l << endl ; 

				table[i][j] = table[i+1][j-1] + 2; 
				if (max_length < table[i][j])
				{
					max_length = table[i][j] ;
				}
				start_index = i; 
			}
			else // Retain the previous count. 
			{
				table[i][j] = table[i+1][j-1]; 
			}	
		}
	}
}
int main ()
{
	string s = "Test"; 
	int start_index = 0, max_length = 0; 

	longestPalindromicSubstring(s, start_index, max_length); 

	cout << "Longest palindromic substring is : " << s.substr(start_index, max_length) << " of length : " << max_length << endl; 
	return 0; 
}