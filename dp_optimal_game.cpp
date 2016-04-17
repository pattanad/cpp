// Problem statement: Consider a row of n coins of values v1 . . . vn, where n
// is even. We play a game against an opponent by alternating turns. In each
// turn, a player selects either the first or last coin from the row, removes
// it from the row permanently, and receives the value of the coin. Determine
// the maximum possible amount of money we can definitely win if we move
// first.

// Note: The opponent is as clever as the user.

#include <iostream> 
#include <vector>

using namespace std; 

// Lets understand the problem correctly here.  We would need to select the moves which would maximize the amount of money which we can definitely win. 
// The opponent is as intelligent as the player.  

// This means that the  opponent would make a move which would minimize our win. 
// if F[i,j] is the array which contains the coins from index i to index j, then there are two cases : 
// 1: if we select V[i], then we would have a choice to pick from F[i+2, j] (if opponent picks V[i+1])
// or F[i+1, j-1] (if opponent picks V[j]). 
// 2. If we select V[j], then we would have a choice to pick from F[i, j-2] (if opponent picks V[j-1])
// or F[i+1, j-1] (if opponent picks V[i]). 
// Since the opponent is clever, he would minimize our win. So we would have to consider that into account and select the min value 
// among (F[i+2, j], F[i+1, j-1]) and min value among (F[i+1, j-1], F[i, j-2]). Given these two choices, we select the max. 

int compute_strategy(vector<int>& array) {
	int N = array.size(); 

	int table[N][N], x, y ,z; 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			table[i][j] = 0; 
		}
	}

	for (int gap = 0; gap < N; gap++) {
		for (int i = 0, j = gap; j < N; j++, i++) {
			x = (i+2 <= j) ? table[i+2][j] : 0; 
			y = (i+1 <= j-1) ? table[i+1][j-1] : 0; 
			z = (i <= j-2) ? table[i][j-2] : 0; 

			table[i][j] = max(array[i] + min(x,y), array[j] + min(y,z)); 
		}
	}

	return table[0][N-1]; 
}

int main() {
	vector<int> array = {20, 30, 2, 2, 2, 10}; 

	int result = compute_strategy(array); 

	cout << "The maximum amount that we can win is : " << result << endl; 

	return 0;
} 