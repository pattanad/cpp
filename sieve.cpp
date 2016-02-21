#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std; 


int main() 
{
	int N = 10000; 
	vector<int> primes;
	stack<int> sprimes;  
	bool A[N]; 
	for (int i = 0; i < N; i++) {
		A[i] = true; 
	}

	A[0] = A[1] = false; 

	for (int i = 2; i < sqrt(N); i++) 
	{
		if (A[i]) 
		{
			for (int j = i*i; j < N; j+=i) 
			{
				A[j] = false;
			}
		}
	}

	for (int i  = 0; i < N; i++) {
		if (A[i]) {
			primes.push_back(i);
			sprimes.push(i);  
		}
	}

	stack<int> sprimes2 = sprimes; 

	while (!sprimes2.empty()) {
		cout << sprimes2.top() << " "; 
		sprimes2.pop();
	}
	cout << endl;

	for (auto prime : primes) {
		cout << prime << " " ; 
	}
	cout << endl; 

	cout << "Size of primes : " << primes.size() << endl; 
	return 0;
}