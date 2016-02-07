#include <iostream>
#include <algorithm>

using namespace std; 

bool isAnagram1(string str1, string str2)
{
	// This method uses sorting. The two strings are sorted and then compared. 
	sort(begin(str1), end(str1));
	sort(begin(str2), end(str2));

	return (str1 == str2); 
}

bool isAnagram2(string str1, string str2)
{
	// This method follows thhe hashing technique. Uses a char array of 256. Only for ascii characters. 
	int str1_count[256]; 
	int str2_count[256];

	for (int i = 0; i < 256; i++)
	{
		str1_count[i] = 0; 
		str2_count[i] = 0; 
	} 

	for (auto ch : str1)
	{
		str1_count[ch]++; 
	}

	for (auto ch : str2)
	{
		str2_count[ch]++; 
	}

	for (int i = 0; i < 256; i++)
	{
		if (str1_count[i] != str2_count[i])
		{
			return false;
		}
	}
	return true; 
}

int main()
{
	string str1 = "hello"; 
	string str2 = "lehloo";

	// We can use isAnagram1 if we want the sorting method.  
	if (isAnagram2(str1, str2))
	{
		cout << str1 << " and " << str2 << " are anagrams of each other" << endl; 
	}
	else 
	{
		cout << str1 << " and " << str2 << " are not anagrams." << endl; 
	}
	return 0;
}