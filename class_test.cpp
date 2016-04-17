#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std; 


class Animal {
	string name; 
	//int legs; 

public:
	void printObj() {
		cout << name << endl; //" " << legs << endl; 
	}

	Animal() {
		int i = 0; 

		while(i < 10) {
			cout << "Hurray!! "; 
			i++;
		}
		cout << endl; 
	}
};

int main() {
	Animal a; 

	a.printObj(); 

	//memset(&a, 'a', sizeof(a)); 
	a.printObj(); 



	cout << sizeof(a) << endl; 
	return 0; 
}