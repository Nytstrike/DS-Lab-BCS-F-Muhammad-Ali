#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Global comparison counter
long long comparisons = 0;

// Merge function to merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to get array input from user
void getArrayInput(vector<int>& arr, int arrayNum) {
    cout << "\nEnter 10 integers for Array " << arrayNum << ":\n";
    for (int i = 0; i < 10; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
}

int main() {
    cout << "========================================\n";
    cout << "  Merge Sort on Combined Arrays\n";
    cout << "========================================\n";
    
    // Initialize two arrays of size 10
    vector<int> array1(10);
    vector<int> array2(10);
    
    // Get input for first array
    getArrayInput(array1, 1);
    
    // Get input for second array
    getArrayInput(array2, 2);
    
    // Display the input arrays
    cout << "\n--- Input Arrays ---\n";
    cout << "Array 1: ";
    printArray(array1);
    cout << "Array 2: ";
    printArray(array2);
    
    // Combine both arrays
    vector<int> combinedArray;
    combinedArray.reserve(20);
    
    for (int num : array1) {
        combinedArray.push_back(num);
    }
    for (int num : array2) {
        combinedArray.push_back(num);
    }
    
    cout << "\n--- Combined Array (Before Sorting) ---\n";
    cout << "Combined Array: ";
    printArray(combinedArray);
    cout << "Total elements: " << combinedArray.size() << endl;
    
    // Reset comparison counter
    comparisons = 0;
    
    // Apply merge sort and measure time
    auto start = high_resolution_clock::now();
    mergeSort(combinedArray, 0, combinedArray.size() - 1);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);
    
    // Display results
    cout << "\n--- After Merge Sort ---\n";
    cout << "Sorted Array: ";
    printArray(combinedArray);
    
    cout << "\n--- Performance Metrics ---\n";
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Time Taken: " << duration.count() << " microseconds" << endl;
    cout << "Time Taken: " << fixed << duration.count() / 1000.0 << " milliseconds" << endl;
    
    // Verify sorting
    bool isSorted = true;
    for (size_t i = 1; i < combinedArray.size(); i++) {
        if (combinedArray[i] < combinedArray[i - 1]) {
            isSorted = false;
            break;
        }
    }
    
    cout << "\nSorting Status: " << (isSorted ? "SUCCESS" : "FAILED") << endl;
    cout << "========================================\n";
    
    return 0;
}