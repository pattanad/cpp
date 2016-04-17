// This eg tries to find out the min absolute difference between 2 sets of a given array. 

#include <iostream>
#include <vector>

using namespace std; 

int findMinDiff(const vector<int>& array) {
	int N = array.size(); 

	int sum = 0; 
	for (auto n : array) {
		sum += n; 
	}

	bool partition[sum/2 + 1][N+1]; 

	for (int i = 0; i <= N; i++) {
		partition[0][i] = true; 
	}

	for (int i = 1; i <= sum/2; i++) {
		partition[i][0] = false; 
	}

	for (int i = 1; i <= sum/2; i++) {
		for (int j = 1; j <= N; j++) {
			partition[i][j] = partition[i][j-1]; 

			if (i >= array[j-1]) {
				partition[i][j] = partition[i][j] || partition[i-array[j-1]][j-1]; 
			}
		}
	}
	
	/*for (int i = 0; i <= sum/2; i++) {
		for (int j = 0; j <= N; j++) {
			cout << partition[i][j] << " "; 
		}
		cout << endl; 
	}*/

	int minDiff = 0; 
	for (int i = sum/2; i >= 0; i--) {
		if (partition[i][N]) {
			minDiff = sum - 2*i;
			break;  
		}	
	}

	return minDiff; 
}

int main() {
	vector<int> array = {1, 5, 11, 2}; 

	for (auto n : array) {
		cout << n << " ";
	}
	cout << endl; 
	cout << "The min difference between 2 sets of this array : " << findMinDiff(array) << endl;
	return 0;  
}