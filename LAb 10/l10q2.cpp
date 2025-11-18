#include <iostream>
using namespace std;

class HeapValidator
{
private:
    int getParentIndex(int i) { return (i - 1) / 2; }
    int getLeftChildIndex(int i) { return 2 * i + 1; }
    int getRightChildIndex(int i) { return 2 * i + 2; }

    void swapValues(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void pushDown(int arr[], int size, int index)
    {
        int maxIndex = index;
        int leftChild = getLeftChildIndex(index);
        int rightChild = getRightChildIndex(index);

        if (leftChild < size && arr[leftChild] > arr[maxIndex])
            maxIndex = leftChild;

        if (rightChild < size && arr[rightChild] > arr[maxIndex])
            maxIndex = rightChild;

        if (maxIndex != index)
        {
            swapValues(arr[index], arr[maxIndex]);
            pushDown(arr, size, maxIndex);
        }
    }

    void constructMaxHeap(int arr[], int size)
    {
        int startIndex = (size / 2) - 1;
        for (int i = startIndex; i >= 0; i--)
        {
            pushDown(arr, size, i);
        }
    }

public:
    bool isMaxHeap(int arr[], int size)
    {
        int lastParent = (size / 2) - 1;

        for (int i = 0; i <= lastParent; i++)
        {
            int leftChild = getLeftChildIndex(i);
            int rightChild = getRightChildIndex(i);

            if (leftChild < size && arr[i] < arr[leftChild])
                return false;

            if (rightChild < size && arr[i] < arr[rightChild])
                return false;
        }
        return true;
    }

    void sortArrayAscending(int arr[], int size)
    {
        constructMaxHeap(arr, size);

        for (int i = size - 1; i > 0; i--)
        {
            swapValues(arr[0], arr[i]);
            pushDown(arr, i, 0);
        }
    }

    void displayArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {8, 7, 6, 5, 4};
    int size = 5;

    HeapValidator validator;

    cout << "Original Array: ";
    validator.displayArray(arr, size);

    cout << "Is Max Heap: " << (validator.isMaxHeap(arr, size) ? "Yes" : "No") << endl;

    validator.sortArrayAscending(arr, size);

    cout << "Sorted Array (Ascending): ";
    validator.displayArray(arr, size);

    return 0;
}