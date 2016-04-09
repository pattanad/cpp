#include <iostream>

using namespace std; 

class Animal {
public: 
	Animal() {}
	Animal(string name) : m_name(name) {}
	~Animal() {}

	string getName() {
		return m_name;
	}
protected:
 	string m_name;
};

class Dog : public Animal {
public:
	Dog() {}
	Dog(string name) : Animal(name) {
		m_name = name; 
	}
	~Dog() {}
};

int main() {

	Animal* animal = new Animal("Tiger"); 
	Animal* animal2 = new Dog("Snoopy"); 

	cout << animal->getName() << endl; 
	cout << animal2->getName() << endl; 

	return 0; 
}