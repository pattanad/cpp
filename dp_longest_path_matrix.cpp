// In this program, we need to find a longest path in an n*n matrix having unique elements from 1 to n^2. 
#include <iostream> 
#include <vector>
#include <climits>

using namespace std; 

int findPath(const vector<vector<int>>& matrix, int N, vector<vector<int>>& dp, int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= N) {
		return 0; 
	}

	if (dp[i][j] != -1) {
		return dp[i][j]; 
	}

	if (i+1 < N && (matrix[i][j] + 1 == matrix[i+1][j])) {
		dp[i][j] = 1 + findPath(matrix, N, dp, i+1, j); 
	}
	else if (i-1 >= 0 && (matrix[i][j] + 1 == matrix[i-1][j])) {
		dp[i][j] = 1 + findPath(matrix, N, dp, i-1, j);
	}
	else if (j+1 < N && (matrix[i][j] + 1 == matrix[i][j+1])) {
		dp[i][j] = 1 + findPath(matrix, N, dp, i, j+1); 
	}
	else if (j-1 >= 0 && (matrix[i][j] + 1 == matrix[i][j-1])) {
		dp[i][j] = 1 + findPath(matrix, N, dp, i, j-1); 
	}
	else {
		dp[i][j] = 1; 
	}

	return dp[i][j]; 
}

int findLongestPath(const vector<vector<int>>& matrix) {
	int N = matrix.size(); 

	vector<vector<int>> dp(N); 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i].push_back(-1); 
		}
	}

	int longest_path = INT_MIN; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == -1) {
				int path = findPath(matrix, N, dp, i, j); 
				if (longest_path < path) {
					longest_path = path; 
				}
			} 
		}
	}
	return longest_path; 
}

int main () {
	vector<vector<int>> matrix(3); 
	matrix[0] = {1, 2, 9}; 
	matrix[1] = {5, 3, 8}; 
	matrix[2] = {4, 6, 7}; 

	cout << "Longest path in this matrix is : " << findLongestPath(matrix) << endl; 
	return 0;
}