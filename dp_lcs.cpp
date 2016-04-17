#include <iostream>

using namespace std; 

// Program to find the longest common subsequence. 
int lcs (const string& s1, const string& s2) {
	size_t N = s1.size(); 
	size_t M = s2.size(); 

	int table[N+1][M+1]; 

	// If any of the string length is zero, then the LCS is zero. Base case. 
	for (int i = 0; i <= N; i++) {
		table[i][0] = 0; 
	}

	for (int i = 0; i <= M; i++) {
		table[0][i] = 0; 
	}

	// The logic recursion is : L(i,j) be the longest common subsequence of two strings of length i and j. Then
	// L(i, j) = L(i-1, j-1) + 1 if s1[i] == s2[j] 
	// L(i, j) = max(L(i-1, j), L(i, j-1)) otherwise. 
	//
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (s1[i-1] == s2[j-1]) { 
				table[i][j] = table[i-1][j-1] + 1; 
			}
			else {
				table[i][j] = max(table[i-1][j], table[i][j-1]); 
			}
		}
	}

	return table[N][M]; 
}

int main () {
	string s1 = "test1"; 
	string s2 = "test2"; 

	cout << "Longest common subsequence of strings : " << s1 << " and " << s2 << " is : " << lcs(s1, s2) << endl; 
	return 0; 
}