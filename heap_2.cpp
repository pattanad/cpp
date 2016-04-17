#include <iostream>
#include <vector> 

using namespace std; 

class MaxHeap {
public: 
    MaxHeap() { }
    ~MaxHeap() { }
    
    void insert (int data) {
        max_heap.push_back(data); 
        upheap(max_heap.size() -1); 
    }
    
    int pop() {
        int max = -1; 
        if (!max_heap.empty()) {
        	max = max_heap[0]; 		
            swap(max_heap[0], max_heap[max_heap.size() - 1]); 
            max_heap.pop_back(); 
            downheap(0); 
        }
        return max; 
    }
    
    bool isEmpty() {
        return max_heap.empty(); 
    }

    void print_heap() {
    	for (auto n : max_heap) {
    		cout << n << " "; 
    	}
    	cout << endl; 
    }
    
private:
    int parent(int index) {
        int p = -1; 
        if (index > 0) {
            p = (index - 1)/2; 
        }
        return p; 
    }
    
    int left(int index) {
        int l = -1; 
        if (2*index + 1 < max_heap.size()) {
            l = 2*index + 1; 
        }
        return l;
    }
    
    int right(int index) {
        int r = -1; 
        if (2*index + 2 < max_heap.size()) {
            r = 2*index + 2;
        }
        return r; 
    }
    
    void upheap(int index) {
        int p = parent(index); 
        
        while ((p != -1) && max_heap[p] < max_heap[index]) {
            swap(max_heap[p], max_heap[index]); 
            index = p; 
            p = parent(index); 
        }
    } 
    
    void downheap(int index) {
        int l = left(index); 
        int r = right(index); 
        int max = index; 
        while (r != -1 || l != -1) {
            if (r != -1) {
                // this means that both children are present. 
                max = (max_heap[l] > max_heap[r]) ? l : r; 
                
                if (max_heap[index] < max_heap[max]) {
                    swap(max_heap[max], max_heap[index]); 
                    index = max;
                }
                else {
                    break; 
                } 
            }
            else {
                // Only left child; 
                if (max_heap[index] < max_heap[l]) {
                    swap(max_heap[index], max_heap[l]); 
                    index = l; 
                }
                else {
                    break; 
                }
            }
            l = left(index); 
            r = right(index); 
        }
    }
    
    vector<int> max_heap; 
};

class MinHeap {
public:
	MinHeap() {}
	~MinHeap() {}

	void insert(int data) {
		min_heap.push_back(data); 
		upheap(min_heap.size()-1); 
	}

	int pop() {
		int min = -1; 
		if (!min_heap.empty()) {
			min = min_heap[0]; 
			swap(min_heap[0], min_heap[min_heap.size() - 1]); 
			min_heap.pop_back(); 
			downheap(0); 
		}
		return min; 
	}

	bool isEmpty() {
		return min_heap.empty();
	}

	void print_heap() {
		for (auto n : min_heap) {
			cout << n << " ";
		}
		cout << endl; 
	}
private:
	int parent(int index) {
		int p = -1; 
		if (index > 0) {
			p = (index - 1)/2; 
		}
		return p; 
	}

	int left(int index) {
		int l = -1; 
		if (2*index +1 < min_heap.size()) {
			l = 2*index + 1;
		}
		return l; 
	} 

	int right(int index) {
		int r = -1;
		if (2*index + 2 < min_heap.size()) {
			r = 2*index + 2;
		}
		return r; 
	}

	void upheap(int index) {
		int p = parent(index); 
		while (p != -1 && min_heap[index] < min_heap[p]) {
			swap(min_heap[index], min_heap[p]); 
			index = p; 
			p = parent(index); 
		}
	}

	void downheap(int index) {
		int l = left(index) ;
		int r = right(index); 

		while (l != -1 || r != -1) {
			int min = -1;
			if (r != 1) {
				// both children are present. 
				min = (min_heap[l] < min_heap[r]) ? l : r; 
				if (min_heap[index] > min_heap[min]) {
					swap(min_heap[index], min_heap[min]); 
					index = min; 
				}
				else {
					break; 
				}
			}
			else {
				if (min_heap[index] > min_heap[l]) {
					swap(min_heap[index], min_heap[l]); 
					index = l; 
				}
				else {
					break; 
				}
			}
			l = left(index); 
			r = right(index); 
		}
	}
	vector<int> min_heap; 
};

int main() {
	MinHeap m; 

	m.insert(4);
	m.insert(5);
	m.insert(2);
	m.insert(3);
	m.insert(6);
	m.insert(1);
	m.insert(7);


	m.print_heap(); 

	while (!m.isEmpty()) {
		cout << m.pop() << endl; 
	}
}