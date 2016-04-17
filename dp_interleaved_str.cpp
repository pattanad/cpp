//Given three strings A, B and C. Write a function that checks whether C is an
//interleaving of A and B. C is said to be interleaving A and B, if it
//contains all characters of A and B and order of all characters in individual
//strings is preserved

// The logic is to implement a dynamic programming solution to store the result of smaller sub-problems. 
// let A and B be two strings and C be the interleaved string. output should be true or false. 
// there are two cases : 
// 1: A[0] = C[0] ; keep searching for A[1] ... recursively. 
// 2: B[0] = C[0] ; keep searching for B[1] ... recursively.

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

bool isInterleaved(const string& A, const string& B, const string& C) {
	int N = A.size(); 
	int M = B.size(); 

	if (C.size() != M+N) {
		// lengths do not match. Hence return false. 
		return false; 
	}

	bool table[N+1][M+1]; 

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			table[i][j] = false; 
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0 && j == 0) {
				table[i][j] = true; 
			}
			else if (i == 0 && B[j-1] == C[j-1]) {
				table[i][j] = table[i][j-1]; 
			}
			else if (j == 0 && A[i-1] == C[i-1]) {
				table[i][j] = table[i-1][j]; 
			}
			else if (A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]) {
				table[i][j] = table[i-1][j]; 
			}
			else if (A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1]) {
				table[i][j] = table[i][j-1]; 
			}
			else if (A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]) {
				table[i][j] = table[i-1][j] || table[i][j-1]; 
			}
		}
	}

	return table[N][M]; 
}

void test(const string& A, const string& B, const string& C) {
	if (isInterleaved(A, B, C)) {
		cout << C << " is interleaved of " << A << " and " << B << endl; 
	}
	else {
		cout << C << " is not interleaved of " << A << " and " << B << endl; 
	}
}

int main() {
    test("XXY", "XXZ", "XXZXXXY");
    test("XY" ,"WZ" ,"WZXY");
    test ("XY", "X", "XXY");
    test ("YX", "X", "XXY");
    test ("XXY", "XXZ", "XXXXZY");

    return 0;
}