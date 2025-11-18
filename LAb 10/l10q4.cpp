#include <iostream>
using namespace std;

class HeapConverter
{
private:
    int getLeftChildIndex(int i) { return 2 * i + 1; }
    int getRightChildIndex(int i) { return 2 * i + 2; }

    void swapElements(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void siftDown(int arr[], int size, int index)
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
            swapElements(arr[index], arr[maxIndex]);
            siftDown(arr, size, maxIndex);
        }
    }

public:
    void transformMinHeapToMaxHeap(int arr[], int size)
    {
        int startIndex = (size / 2) - 1;

        for (int i = startIndex; i >= 0; i--)
        {
            siftDown(arr, size, i);
        }
    }

    void displayArray(int arr[], int size, string label)
    {
        cout << label;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    int arr[100];

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    cout << "Enter " << n << " elements (Min Heap): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    HeapConverter converter;

    converter.displayArray(arr, n, "Original Min Heap: ");

    converter.transformMinHeapToMaxHeap(arr, n);

    converter.displayArray(arr, n, "Converted Max Heap: ");

    return 0;
}