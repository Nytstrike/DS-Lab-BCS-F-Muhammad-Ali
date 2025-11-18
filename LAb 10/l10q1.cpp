#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    int getParent(int index) { return (index - 1) / 2; }
    int getLeftChild(int index) { return 2 * index + 1; }
    int getRightChild(int index) { return 2 * index + 2; }

    void siftUp(int index)
    {
        while (index > 0 && heap[index] > heap[getParent(index)])
        {
            swap(heap[index], heap[getParent(index)]);
            index = getParent(index);
        }
    }

    void siftDown(int index)
    {
        int size = heap.size();
        int largest = index;
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            siftDown(largest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void display()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    bool updateValue(int index, int newValue)
    {
        if (index < 0 || index >= heap.size())
        {
            cout << "Error: Index out of bounds" << endl;
            return false;
        }

        int oldValue = heap[index];
        heap[index] = newValue;

        if (newValue > oldValue)
            siftUp(index);
        else
            siftDown(index);

        return true;
    }

    bool removeAt(int index)
    {
        if (index < 0 || index >= heap.size())
        {
            cout << "Error: Index out of bounds" << endl;
            return false;
        }

        heap[index] = heap.back();
        heap.pop_back();

        if (index < heap.size())
        {
            siftUp(index);
            siftDown(index);
        }

        return true;
    }

    int getSize() { return heap.size(); }
};

int main()
{
    MaxHeap maxHeap;

    maxHeap.insert(8);
    maxHeap.insert(7);
    maxHeap.insert(6);
    maxHeap.insert(5);
    maxHeap.insert(4);

    cout << "Initial Max Heap: ";
    maxHeap.display();

    maxHeap.updateValue(3, 10);
    cout << "Heap after update: ";
    maxHeap.display();

    maxHeap.removeAt(1);
    cout << "Heap after delete: ";
    maxHeap.display();

    return 0;
}