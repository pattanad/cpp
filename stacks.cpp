#include <iostream>
#include <memory>

using namespace std; 

/*
 Need to implement a stack first. And then expand the concept to imiplement 3 stacks 
 using a single array. 
*/

class Stack
{
public:
	Stack() : stack(nullptr), top(0), size_(0)
	{
	}

	Stack(int size): stack(new int[size]), top(0), size_(size)
	{
	}

	~Stack()
	{
	}

	void setSize(int size)
	{
		size_ = size; 
	}

	void push(int data)
	{
		if (isFull())
		{
			cout << "Stack is full" << endl; 
			return; 
		}
		stack[top++] = data;  
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl; 
			return -1; 
		}
		return stack[--top];
	}

private:

	bool isEmpty()
	{
		return (top <= 0); 
	}

	bool isFull()
	{
		return (top == size_); 
	}

	unique_ptr<int[]> stack; 
	int top;
	int size_;  
};

class StackOf3
{
public:
	StackOf3(int totalSize) : size_(totalSize), stack(new int[totalSize])
	{
		for (int i = 0; i < 3; i++)
		{ 
			top[i] = i*size_/3; 
		}	
	}

	StackOf3() : size_(0), stack(nullptr)
	{
		for (int i = 0; i < 3; i++)
		{ 
			top[i] = i*size_/3; 
		} 
	}

	~StackOf3()
	{
	}

	void setSize(int size)
	{
		size_ = size;

		for (int i = 0; i < 3; i++)
		{ 
			top[i] = i*size_/3; 
		}	
	}

	void push (int data, int stackNo)
	{
		if (isFull(stackNo))
		{
			cout << "Stack " << stackNo << " is full" << endl ; 
			return; 
		}
		stack[top[stackNo-1]++] = data; 
	}

	int pop(int stackNo)
	{
		if (isEmpty(stackNo))
		{
			cout << "Stack is empty" << endl; 
			return -1; 
		}
		return stack[--top[stackNo-1]]; 
	}

private:
	bool isEmpty(int stackNo)
	{
		return (top[stackNo-1] <= (stackNo-1)*size_/3);
	}

	bool isFull(int stackNo)
	{
		return (top[stackNo-1] == stackNo*size_/3);
	}

	int size_; 
	unique_ptr<int[]> stack;
	int top[3]; 
};

// Implements a stack of integers.  The size of the stack should be given . 

int main ()
{
	cout << "Usage of unique ptr" << endl ; 

	unique_ptr<int[]> int_array(new int[10]); 

	for (int i = 0; i < 10; i++)
	{
		int_array[i] = i; 
	}

	for (int i = 0; i < 10; i++)
	{
		cout << int_array[i] << " "; 
	}
	cout << endl; 

	cout << "Using the stack now" << endl; 

	Stack s(10); 

	for (int i = 0; i < 10; i++)
	{
		cout << "Pushing " << i << endl; 
		s.push(i); 
	}

	s.push(10); 

	for (int i = 0; i < 10; i++)
	{
		cout << "Popping : " << s.pop() << endl; 
	}

	cout << " Now Testing Stack of 3 immplementation" << endl; 

	StackOf3 s3(30); 

	for (int j = 1; j <= 3; j++)
	{
		cout << "pushing into stack : " << j << endl; 
		for (int i = 0; i < 10; i++)
		{
			cout << "Pushing " << i << " into stack " << j << endl; 
			s3.push(i, j); 
		}
		cout << "Completed pushing into stack " << j << endl; 
	}

	for (int j = 1; j <= 3; j++)
	{
		cout << "popping elements from stack : " << j << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "Popping out " << s3.pop(j) << " from stack " << j << endl ; 
		}
		cout << "Completed Popping elements from stack : " << j << endl; 
	}

	return 0; 
}