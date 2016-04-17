#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Heap {
public:
	Heap(){}
	~Heap() {}

	int pop() {
		if (!heap.empty()) {
			int element = heap[0]; 
			heap[0] = heap.back(); 
			heap.pop_back(); 
			downHeap(0); 
			return element; 
		}
		else {
			return -1; 
		}
	}

	void push(int element) {
		heap.push_back(element); 

		upHeap(heap.size() - 1); 
	}

	int top() {
		if (!heap.empty()) {
			return heap[0]; 
		}
		else return -1; 
	}

	bool empty() {
		return heap.empty();
	}

protected:
	void downHeap(int index) {

		if (index >= heap.size()) {
			cout << "downheap : index invalid" << endl; 
			return; 
		}

		cout << "downheap : Working on index " << index << " value : " << heap[index] << endl; 

		int left_index = left(index); 
		int right_index = right(index);

		if (right_index == -1 && left_index == -1) {
			// the node is a leaf node. return .
			cout << "downHeap : a leaf node reached." << endl; 
			return;
		} 
		else if (right_index == -1 && left_index != -1) {
			if (heap[index] > heap[left_index]) {
				cout << "Swapping " << heap[index] << " with left index" << heap[left_index] << endl; 
				swap(heap[index], heap[left_index]); 
				return; 
			}
		}

		if (left_index != -1 && right_index != -1) {
			if (heap[index] > heap[left_index] || heap[index] > heap[right_index]) {
				int min_index = (heap[left_index] < heap[right_index])? left_index : right_index;
				cout << "swapping " << heap[index] << " with " << heap[min_index] << endl;  
				swap(heap[index], heap[min_index]);
				downHeap(min_index);  
			}
		}
	}

	void upHeap(int index) {
		if (index == -1) {
			cout << "upheap : invalid index " << endl; 
			return; 
		}

		cout << "Upheap : working on index " << index << " value : " << heap[index] << endl; 
		int parent_index = parent(index); 

		if (parent_index != -1) {
			if (heap[index] < heap[parent_index]) {
				cout << "Swapping " << heap[index] << " with " << heap[parent_index] << endl; 
				swap(heap[parent_index], heap[index]);
				upHeap(parent_index);  
			}
		} 
	}

	int parent(int index) {
		if (index > 0) {
			return (index + 1)/2 - 1; 
		}
		else {
			return -1; 
		}
	}

	int left(int index) {
		if ((2*index + 1) < heap.size()) {
			return 2*index + 1;
		}
		else {
			return -1; 
		}
	}

	int right(int index) {
		if ((2*index + 2) < heap.size()) {
			return 2*index + 2;
		}
		else {
			return -1; 
		}
	}

private:
	vector<int> heap; 
} ;

int main () {
	// vector<int> heap = {4, 2, 5, 6, 1, 3, 7, 9, 8}; 
	Heap heap; 

	heap.push(4); 
	heap.push(2); 
	heap.push(5); 
	heap.push(6); 
	heap.push(1); 
	heap.push(3); 
	heap.push(7); 
	heap.push(9); 
	heap.push(8);

	cout << "Top of the heap : " << heap.top() << endl; 



	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	cout << heap.pop() << endl;  
	// cout << heap.pop() << endl;  

	cout << endl; 
}