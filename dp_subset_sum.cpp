// In this problem, we see if any subset of a given set of integers has a sum equal to given sum. 
#include <iostream> 
#include <vector>

using namespace std; 

bool isSubsetSum(const vector<int>& array, int sum) {
	int N = array.size(); 
	bool subsetsum[sum+1][N+1]; 

	for (int i = 0; i <= N; i++) {
		subsetsum[0][i] = true; 
		// If sum is zero, then true. 
	}

	for (int i = 1; i <= sum; i++) {
		subsetsum[i][0] = false; 
		// If number is 0, then false. 
	}

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= N; j++) {
			subsetsum[i][j] = subsetsum[i][j-1]; 

			if (i >= array[j-1]) {
				subsetsum[i][j] = subsetsum[i][j] || subsetsum[i-array[j-1]][j-1]; 
			}
		}
	}
	return subsetsum[sum][N]; 
}

int main () {
	vector<int> array = {3, 34, 4, 12, 5, 2}; 
	int sum = 9; 

	if (isSubsetSum(array, sum)) {
		cout << "Array has a subset equals " << sum << endl; 
	}
	else {
		cout << "Array does not have a subset equalling " << sum << endl; 
	}
	return 0;
}