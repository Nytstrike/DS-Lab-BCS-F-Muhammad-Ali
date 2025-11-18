#include <iostream>
using namespace std;

class KthLargestFinder
{
private:
    int getParentIndex(int i) { return (i - 1) / 2; }
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

    void constructMaxHeap(int arr[], int size)
    {
        int startIndex = (size / 2) - 1;
        for (int i = startIndex; i >= 0; i--)
        {
            siftDown(arr, size, i);
        }
    }

public:
    int findKthLargest(int arr[], int size, int k)
    {
        if (k < 1 || k > size)
        {
            cout << "Error: K is out of valid range" << endl;
            return -1;
        }

        constructMaxHeap(arr, size);

        for (int i = size - 1; i >= size - k + 1; i--)
        {
            swapElements(arr[0], arr[i]);
            siftDown(arr, i, 0);
        }

        return arr[0];
    }

    void displayArray(int arr[], int size)
    {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n, k;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter K (position of largest element): ";
    cin >> k;

    KthLargestFinder finder;
    finder.displayArray(arr, n);

    int result = finder.findKthLargest(arr, n, k);

    if (result != -1)
    {
        cout << "The " << k << "th largest element is: " << result << endl;
    }

    return 0;
}