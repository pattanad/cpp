#include <iostream> 
#include <vector>
#include <climits>

using namespace std; 

int lis(const vector<int>& array) {
	int N = array.size(); 

	int LIS[N]; 

	// Initialize the array. Each element has a LIS of 1. Base case.  
	for (int i = 0; i < N; i++) {
		LIS[i] = 1; 
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			// Here check if the array element is in increasing order. 
			if (array[i] > array[j] && LIS[i] < LIS[j] + 1) {
				LIS[i] = LIS[j] + 1; 
			}
		}
	}

	int max_lis = INT_MIN; 

	for (int i = 0; i < N; i++) {
		if (max_lis < LIS[i]) {
			max_lis = LIS[i]; 
		}
	}

	return max_lis; 
}

int main () {
	vector<int> array = {10,22,9,33,21,50,41,60,80}; 

	cout << "Longest increasing subsequence of array : { " ; 
	for (auto n : array) {
		cout << n << " "; 
	}
	cout << "} is : " << lis(array) << endl; 
	return 0; 
}