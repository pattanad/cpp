#include <iostream>

using namespace std; 

struct Node
{
	int data; 
	Node* next; 

	Node(int data_) : data(data_), next(nullptr)
	{
	}

	~Node() 
	{
	}
};

class LinkedList
{
public:
	LinkedList():head(nullptr)
	{
	}

	~LinkedList()
	{
	}

	bool insertElement(int data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			return true;  
		}
		Node* node = head; 

		while (node->next != nullptr)
		{
			node = node->next; 
		}
		node->next = new Node(data); 
		return true; 
	} 

	int getElement(int index)
	{
		int i = 1; 

		Node* node = head; 
		while (node != nullptr && i < index)
		{
			node = node->next; 
			i++; 
		}

		if (i == index)
		{
			return node->data; 
		}
		else 
		{
			return -1; 
		}
	}

	bool deleteElement(int data)
	{
		if (head == nullptr)
		{
			cout << "List empty. Nothing to be deleted." << endl; 
			return false; 
		}

		Node* node = head->next; 
		Node* prev = head; 

		if (head->data == data)
		{
			// delete head
			Node* newHead = head->next; 
			delete head; 
			head = newHead; 
			return true;
		}

		while (node != nullptr)
		{
			if (node->data == data)
			{
				// Save link of the next node. 
				prev->next = node->next; 

				delete node; 
				return true; 
			}
			else
			{
				node = node->next; 
				prev = prev->next; 
			}
		}
		cout << "Element not found" << endl; 
		return false; 
	} 
	
	void printList()
	{
		Node* node = head; 

		while (node != nullptr)
		{
			cout << node->data << " " ;
			node = node->next; 
 		}
 		cout << endl; 
	}

	void reverseList()
	{
		if (head->next == nullptr)
		{
			// The list consists of one element. Do nothing. 
			return;
		}

		Node* current = head;
		Node* next = nullptr;
		Node* prev = nullptr; 

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;  
			prev = current;
			current =  next; 
		}
		head = prev; 
	}

	Node* reverseList(Node* head, int size)
	{
		Node* current = head; 
		Node* next = nullptr;
		Node* prev = nullptr; 

		int listSize = 1;

		while (current != nullptr && listSize <= size)
		{
			next = current->next;
			current->next = prev; 
			prev = current; 
			current = next; 

			listSize++; 
		}

		if (next != nullptr)
		{
			head->next = reverseList(next, size); 
		}

		return prev; 		
	}

	void reverseList(int size)
	{
		head = reverseList(head, size); 
	}

	Node* altReverseList(Node* head, int size)
	{
		Node* current = head; 
		Node* next = nullptr; 
		Node* prev = nullptr; 

		int count = 1;

		while (current != nullptr && count <= size)
		{
			next = current->next; 
			current->next = prev;
			prev = current; 
			current = next; 
			count++;
		}

		// Now the head would be pointing to the kth node 
		// Now we need to advance current to next k nodes and then recurse. 
		if (head != nullptr)
		{
			head->next = current; 
		}

		count = 1; 

		while (current != nullptr && count < size)
		{
			current = current->next;
			count++;  
		}

		// Very tricky logic here.  Not perfectly clear and intuitive. 
		if (current != nullptr)
		{
			current->next = altReverseList(current->next, size);
		}

		return prev; 
	}

	void altReverseList(int size)
	{
		head = altReverseList(head, size); 
	}

	int kthFromEnd(int k)
	{
		Node* ptr1 = head; 
		int count = 0; 
		while (ptr1 != nullptr && count < k)
		{
			ptr1 = ptr1->next; 
			count++; 
		}

		if (count < k)
		{
			return -1; 
		}

		Node* ptr2 = head; 

		while (ptr1 !=  nullptr)
		{
			ptr1 = ptr1->next; 
			ptr2 = ptr2->next; 
		}

		if (ptr2 != nullptr)
		{
			return ptr2->data; 
		}
		else 
		{
			return -1; 
		}
	}

private:
	Node* head; 
};


void addLists(LinkedList& num1, LinkedList& num2, LinkedList& result)
{
	cout << " Num 1: " ; 
	num1.printList(); 

	cout << " Num 2 : " ;
	num2.printList();

	int carry = 0; 
	int i = 1; 
	; 
	int n1 = 0, n2 = 0;
	int n = 0; 
	while (((n1 = num1.getElement(i)) != -1) && ((n2 = num2.getElement(i)) != -1))
	{
		cout << "Iteration : " << i << " n1 : " << n1 << " n2 : " << n2 << endl; 
		int sum = (n1 + n2 + carry)%10 ; 
		carry = (n1 + n2 + carry)/10;

		result.insertElement(sum); 
		i++; 
	}

	cout << "i :" << i << endl;
	if (num1.getElement(i) == -1)
	{
		cout << " Copying elements frm num2 " << endl;
		while ((n = num2.getElement(i)) != -1)
		{
			n = (n + carry)%10; 
			carry = (n + carry)/10;
			result.insertElement(n);
		}
	}
	else
	{
		cout << " Copying elements frm num1 " << endl;
		while ((n = num1.getElement(i)) != -1)
		{
			n = (n + carry)%10; 
			carry = (n + carry)/10;
			result.insertElement(n);
		}
	}
	return; 
}


int main()
{
	LinkedList list; 

	list.insertElement(1); 
	list.insertElement(2); 
	list.insertElement(3); 
	list.insertElement(4); 
	list.insertElement(5); 

	list.printList();

	//list.deleteElement(1);
	//list.printList();

	list.reverseList(); 
	list.printList();

	//reversing the list to get the original list back   
	list.reverseList(); 
	list.printList();

	list.insertElement(6);
	list.insertElement(7);
	list.insertElement(8);
	list.insertElement(9);
	list.insertElement(10);
	list.insertElement(11);
	list.insertElement(12);
	list.printList();


	list.reverseList(4); 
	list.printList(); 
	list.reverseList(4); 
	list.printList();

	list.altReverseList(4);
	list.printList(); 
	list.altReverseList(4);
	list.printList();

	cout << "13th from last : " << list.kthFromEnd(13) << endl;

	cout << "11th element of list : " << list.getElement(11) << endl; 

	LinkedList num1; 
	LinkedList num2; 

	num1.insertElement(5);
	num1.insertElement(6);
	num1.insertElement(3);

	num2.insertElement(8);
	num2.insertElement(4);
	num2.insertElement(2);

	LinkedList result;
	addLists(num1, num2, result);
	result.printList();
	return 0; 
}