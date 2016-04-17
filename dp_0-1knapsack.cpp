// In this problem we find the solution to the 0-1 knapsack problem. Given a list of items with values V and its weight wt, and a sack with capacity W, we need to 
// find the max value we can carry in the sack (W). 
// The recursion can we written as : 
// knapsack(V,wt,W, i) = knapsack(V, wt, W, i-1) --> the item is not included. 
// 					   = knapsack(V, wt, W-wt[i], i-1) --> the item is included. 
// We need to find the max of these values. 
#include <iostream>
#include <vector>

using namespace std; 

int knapsack(const vector<int>& V, const vector<int>& wt, int W) {
	int N = V.size(); 
	int sack[W+1][N+1]; 

	for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0) {
				sack[i][j] = 0; 
			}
			else if (i >= wt[j-1]) {
				// If we can include the current item in the sack, then its a choice whether to include it or not. 
				sack[i][j] = max(sack[i][j-1], sack[i-wt[j-1]][j-1] + V[j-1]); 
			}
			else {
				sack[i][j] = sack[i][j-1]; 
			}
		}
	}

	// We return the last element in the table which indicates a sack of weight W and N items. 
	return sack[W][N]; 
}

int main () {
	vector<int> V = {60, 100, 120}; 
	vector<int> wt = {10, 20, 30};

	int W = 50; 

	cout << "Max value that can be carried in sack of capacity : " << W << " is : " << knapsack(V, wt, W) << endl; 
	return 0;
}