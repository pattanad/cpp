#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX_CHAR_LEN = 256;  

string removeDuplicates(const string& str)
{
	// Solution assuming that the input has characters in the ASCII (8 bit)
	int char_count[MAX_CHAR_LEN];
	string result;  

	for (int i = 0; i < MAX_CHAR_LEN; i++)
	{
		char_count[i] = 0; 
	}

	for (auto ch : str)
	{
		if (char_count[ch] == 0)
		{
			result += ch;  
		}
		char_count[ch]++; 
	}
	return result; 
}

/*
 This function will remove chharaters from the source which are present in the pattern. 
*/
string removeCharacters(const string& source, const string& pattern)
{
	string result; 
	int char_count[MAX_CHAR_LEN]; 

	// Initialize the count array to 0. 
	for (int i = 0; i < MAX_CHAR_LEN; i++)
	{
		char_count[i] = 0; 
	}

	for (auto ch : pattern)
	{
		char_count[ch]++; 
	}

	for (auto ch : source)
	{
		if (char_count[ch] == 0)
		{
			result += ch; 
		}
	}
	return result;
}

void permutationsOfString(string& str, int start, int end, vector<string>& result)
{
	if (start == end)
	{
		result.push_back(str); 
	}
	else 
	{
		for (int i = start; i <= end; i++)
		{
			swap(str[i], str[start]); 
			permutationsOfString(str, start+1, end, result); 
			swap(str[i], str[start]);
		}
	}
}

bool areRotations(string& str1, string& str2)
{
	string combined = str1+str1; 

	if (combined.find(str2) == string::npos)
	{
		return false; 
	}
	else
	{
		return true;
	}
}

string reverseString(string str)
{
 	int start = 0, end = str.size() - 1; 
	while (start < end)
	{
		swap(str[start], str[end]); 
		start++; 
		end--; 
	}
	return str; 
}

string reverseWords(string& str)
{
	string reversed = reverseString(str); 
	string result; 
	int start = 0; 
	int end = 0; 
	int i = 0; 

	while (i < reversed.size())
	{
		if (reversed[i] == ' ')
		{
			result += reverseString(reversed.substr(start, end-start+1));		
			while (reversed[i] == ' ')
			{
				result += reversed[i]; 
				i++;
	
			}
			start = i; 
		}
		else 
		{
			end = i;
			i++;  
		}
	}
	if (start <= end)
	{
		result += reverseString(reversed.substr(start, end-start+1)); 
	}

	return result; 
}

int main ()
{
	cout << "Remove duplicates from a string - BEGIN " << endl; 

	string s1 = "This is a string"; 
	cout << "input string : " << s1 << " resulting string after removing duplicates : " << removeDuplicates(s1) << endl; 

	cout << "Remove duplicates from a string - END" << endl;  

	cout << "Remove characters from first string which are present in the second : BEGIN" << endl; 

	string pattern = "hello"; 

	cout << "Source : " << s1 << " Pattern : " << pattern << " Result : " << removeCharacters(s1, pattern) << endl; 
	
	cout << "Remove characters from first string which are present in the second : END" << endl; 	

	cout << "Printing all permutations of a given string : BEGIN" << endl ; 

	cout << "input : " << pattern  << " : Result : " << endl ; 

	vector<string> result; 
	pattern = "abc"; 
	permutationsOfString(pattern, 0, pattern.size() - 1, result); 

	for (auto s : result)
	{
		cout << s << " "; 
	} 
	cout << endl; 
	cout << "Printing all permutations of a given string : END" << endl ; 	

	cout << "Are two strings rotations of each other : BEGIN" << endl; 
	string s2 = "ABCD"; 
	string s3 = "CDABE"; 

	if (areRotations(s2, s3))
	{
		cout << "String " << s2 << " and " << s3 << " are rotations of each other" << endl; 
	}
	else 
	{
		cout << "String " << s2 << " and " << s3 << " are not rotations of each other" << endl; 
	}
	cout << "Are two strings rotations of each other : END" << endl; 

	cout << "Reverse words in a string : BEGIN" << endl;

	string s4 = "This is a line" ; 

	cout << "Original : " << s4 << " Reversed : " << reverseWords(s4) << endl;  

	cout << "Reverse words in a string : END" << endl; 

	return 0; 
}