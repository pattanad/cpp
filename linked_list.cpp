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

	return 0; 
}