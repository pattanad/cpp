#include <iostream>
#include <vector>
using namespace std; 

class MaxHeap {
    public: 
    MaxHeap() { }
    ~MaxHeap() { }
    
    void insert(int data) {
        cout << "Inserting data : " << data << endl; 
        max_heap.push_back(data); 
        up_heap(max_heap.size() - 1); 
    }
    
    int pop() {
        if (!max_heap.empty()) {
            int data = max_heap[0]; 
            swap(max_heap[0], max_heap[max_heap.size() - 1]); 
            max_heap.pop_back(); 
            down_heap(0); 
            return data; 
        }
    }

    bool isEmpty() {
        return max_heap.empty(); 
    }

    void printHeap() {
        for (auto n : max_heap) {
            cout << n << " ";
        }
        cout << endl; 
    }
  
    private:

    int left(int index) {
        int left = 2*index+1; 
        if (left < max_heap.size()) {
            cout << "Left index : " << left << " : element : " << max_heap[left] << endl; 
            return left; 
        }
        return -1; 
    }

    int right(int index) {
        int right = 2*index + 2; 
        if (right < max_heap.size()) {
            cout << "Right index : " << right << " : element : " << max_heap[right] << endl; 
            return right; 
        }
        return -1; 
    }

    int parent(int index) {
        if ((index - 1)/2 >= 0) {
            int parent = (index - 1)/2;
            cout << "Parent index : " << parent << " : element : " << max_heap[parent] << endl; 
            return  parent; 
        }
        return -1; 
    }

    void up_heap(int index) {
        while (index > 0) {
            cout << "Up Heap : index : " << index << " : element : " << max_heap[index] << endl; 
            int p = parent(index); 
            if (p != -1) {
                if (max_heap[index] > max_heap[p]) {
                    cout << "Swapping indexes : " << index << " and " << p << endl; 
                    swap(max_heap[index], max_heap[p]); 
                } 
                index = p;
            }
        }   
    }
               
    void down_heap(int index) {
        while (index < max_heap.size()) {
            int left_index = left(index); 
            int right_index = right(index); 
            int max_index = -1; 
            if (left_index == -1) {
                //  leaf node.
                break;  
            }
            else {
                if (right_index != -1) { 
                    // Both children are present. 
                    if (max_heap[index] < max_heap[left_index] || max_heap[index] < max_heap[right_index]) {
                        max_index = (max_heap[left_index] > max_heap[right_index]) ? left_index : right_index; 
                    }
                }
                else {
                    // just left node is present 
                    if (max_heap[index] < max_heap[left(index)]) {
                        max_index = left(index); 
                    }
                }
                if (max_index != -1) {
                    swap(max_heap[index], max_heap[max_index]); 
                    index = max_index; 
                }
                else {
                    break; 
                }
            }
        }
    }
    vector<int> max_heap; 
};


int main() {
    MaxHeap max; 

    max.insert(1); 
    max.insert(2); 
    max.insert(4); 
    max.insert(6); 
    max.insert(3); 
    max.insert(7); 
    max.insert(9); 

    max.printHeap(); 

    while (!max.isEmpty()) {
        cout << max.pop() << endl;
    } 
    return 0; 
}