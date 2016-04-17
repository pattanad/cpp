// In this problem, we would have to find if an array could be partitioned into two subsets such that sum of two subsets is the same. 
#include <iostream>
#include <vector>

using namespace std;

// The idea of recursion is to have either the last element included in the sum or last element not included in the sum. 
// If included : findPartition(arr, i, sum )  = findPartition(arr, i-1, sum-arr[i]); 
// If not included : 						  = findPartition(arr, i-1, sum); 

// So we need to have a 2D array of sum+1 x n and fill in the table bottom up. 

bool findPartition(const vector<int>& array) {
	int sum = 0; 
	int N = array.size(); 

	for (auto n : array) {
		sum += n; 
	}
	if (sum % 2 != 0) {
		return false; 
	}

	bool table[sum/2 + 1][N+1]; 

	for (int i = 0; i <= N; i++) {
		table[0][i] = true; 
		// true if sum is 0. 
	}

	for (int i = 1; i <= sum/2; i++) {
		table[i][0] = false; 
		// false if the array is empty. 
	}

	for (int i = 1; i <= sum/2; i++) {
		for (int j = 1; j <= N; j++) {
			table[i][j] = table[i][j-1]; // Not including the jth element. 
			if (i >= array[j-1]) {
				table[i][j] = table[i][j] || table[i-array[j-1]][j-1];  // the result is Logical OR of element included and element not included. 
			}
		}
	}
	return table[sum/2][N]; 
}

int main() {
	vector<int> array = { 1, 5, 11, 5 };

	// Sum will contain the total sum. we need to find out if the subset has sum equals half the total sum. 
	if (findPartition(array)) {
		cout << "Partition found" << endl; 
	} 
	else {
		cout << "Partition not found" << endl;
	} 
	return 0; 
}