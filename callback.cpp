#include <iostream>
#include <cmath>

using namespace std; 

int main () 
{
	unsigned long twoPow31 = 1 << 31; 

	cout << "Size of : " << sizeof(twoPow31) << endl;  
	cout << twoPow31 << endl; 

	twoPow31 = pow(2, 31); 
	cout << twoPow31 << endl; 
	return 0; 
}