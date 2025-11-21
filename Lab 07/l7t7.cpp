#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace chrono;

long long comparisons = 0;

int partitionFirst(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
        {
            comparisons++;
            i++;
        }
        if (i <= high)
            comparisons++;

        while (j > low && arr[j] > pivot)
        {
            comparisons++;
            j--;
        }
        if (j > low)
            comparisons++;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

int partitionLast(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMedian(vector<int> &arr, int low, int high)
{
    int mid = low + (high - low) / 2;

    comparisons += 3;
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high - 1]);
    int pivot = arr[high - 1];

    int i = low;
    int j = high - 1;

    while (true)
    {
        while (arr[++i] < pivot)
        {
            comparisons++;
        }
        comparisons++;

        while (arr[--j] > pivot)
        {
            comparisons++;
        }
        comparisons++;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            break;
        }
    }

    swap(arr[i], arr[high - 1]);
    return i;
}

void quickSortFirst(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, pi - 1);
        quickSortFirst(arr, pi + 1, high);
    }
}

void quickSortLast(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partitionLast(arr, low, high);
        quickSortLast(arr, low, pi - 1);
        quickSortLast(arr, pi + 1, high);
    }
}

void quickSortMedian(vector<int> &arr, int low, int high)
{
    if (high - low >= 3)
    {
        int pi = partitionMedian(arr, low, high);
        quickSortMedian(arr, low, pi - 1);
        quickSortMedian(arr, pi + 1, high);
    }
    else if (high > low)
    {
      
        for (int i = low + 1; i <= high; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key)
            {
                comparisons++;
                arr[j + 1] = arr[j];
                j--;
            }
            if (j >= low)
                comparisons++;
            arr[j + 1] = key;
        }
    }
}


void printArray(const vector<int> &arr, int limit = 20)
{
    int size = min(limit, (int)arr.size());
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    if (arr.size() > limit)
    {
        cout << "... (" << arr.size() << " elements total)";
    }
    cout << endl;
}


void testQuickSort(vector<int> arr, const string &method)
{
    comparisons = 0;
    vector<int> sortedArr = arr;

    auto start = high_resolution_clock::now();

    if (method == "First")
    {
        quickSortFirst(sortedArr, 0, sortedArr.size() - 1);
    }
    else if (method == "Last")
    {
        quickSortLast(sortedArr, 0, sortedArr.size() - 1);
    }
    else if (method == "Median")
    {
        quickSortMedian(sortedArr, 0, sortedArr.size() - 1);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\n"
         << method << " Element as Pivot:" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    cout << "Sorted (first 20): ";
    printArray(sortedArr, 20);
}

int main()
{
    cout << "QuickSort Performance Comparison\n";
    cout << "=================================\n";

 
    vector<vector<int>> testCases = {
        {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 23, 36, 19, 77, 55},
        {5, 4, 3, 2, 1}, 
        {1, 2, 3, 4, 5}, 
    };

    vector<string> caseNames = {
        "Random Array",
        "Reverse Sorted Array",
        "Already Sorted Array"};

    for (size_t i = 0; i < testCases.size(); i++)
    {
        cout << "\n\n--- Test Case " << (i + 1) << ": " << caseNames[i] << " ---" << endl;
        cout << "Original array: ";
        printArray(testCases[i]);

        testQuickSort(testCases[i], "First");
        testQuickSort(testCases[i], "Last");
        testQuickSort(testCases[i], "Median");
    }

    cout << "\n\n-- Test Case 4: Large Random Array (1000 elements) --" << endl;
    vector<int> largeArray(1000);
    for (int i = 0; i < 1000; i++)
    {
        largeArray[i] = rand() % 10000;
    }

    cout << "Original array (first 20): ";
    printArray(largeArray, 20);

    testQuickSort(largeArray, "First");
    testQuickSort(largeArray, "Last");
    testQuickSort(largeArray, "Median");
    return 0;
}