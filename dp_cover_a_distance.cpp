#include <iostream> 

using namespace std; 

// In this program, we are  given a distance and we need to count the number ways to cover the distance with 1, 2 and 3 steps.  
int main () {
	int distance = 4; 

	int dp_dist[distance+1]; 
	dp_dist[0] = 1; 
	dp_dist[1] = 1; 
	dp_dist[2] = 2; 

	for (int i = 3; i <= distance; i++) {
		dp_dist[i] = dp_dist[i-1] + dp_dist[i-2] + dp_dist[i-3]; 
	}

	cout << "The number of ways to cover the distance : " << distance << " is : " << dp_dist[distance] << endl; 
	return 0;
}