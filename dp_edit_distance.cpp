#include <iostream>

using namespace std; 

int edit_distance(const string& s1, const string& s2) {
	int N = s1.size(); 
	int M = s2.size(); 

	int table[N+1][M+1]; 

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			table[i][j] = 0; 
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			// If any of the string is empty, then the distance would be length of the other string. 
			if (i == 0) {
				table[i][j] = j;
			}

			else if (j == 0) {
				table[i][j] = i; 
			}

			else if (s1[i-1] == s2[j-1]) {
				// The  characters are the same. 
				table[i][j] = table[i-1][j-1]; 
			}
			else {
				// Take in the min of insert, delete or replace. 
				table[i][j] = 1 + min(table[i-1][j-1], min(table[i][j-1], table[i-1][j]));
			}
		}
	}

	// This would contain the edit distance for the strings of lengths M and N. 
	return table[N][M]; 
}

int main () {
	string s1 = "pavan"; 
	string s2 = "manasa"; 


	cout << "The distance between two strings : " << s1 << " and " << s2 << " is : " << edit_distance(s1, s2) << endl; 
	return 0; 
}