#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int traverseIntegers(const string &input, int arr[])
{
    int count = 0;
    int num = 0;
    bool inNumber = false;
    bool isNegative = false;

    for (int i = 0; i < input.length() && count < MAX_SIZE; i++)
    {
        char c = input[i];

        if (c == ' ' || c == '\t')
        {
            if (inNumber)
            {
                arr[count++] = isNegative ? -num : num;
                num = 0;
                inNumber = false;
                isNegative = false;
            }
        }
        else if (c == '-' && !inNumber)
        {
            isNegative = true;
            inNumber = true;
        }
        else if (c >= '0' && c <= '9')
        {
            inNumber = true;
            num = num * 10 + (c - '0');
        }
        else
        {
            return -1;
        }
    }

    if (inNumber)
    {
        arr[count++] = isNegative ? -num : num;
    }

    return count;
}

int getArrayInput(int arr[])
{
    string line;
    int size;

    while (true)
    {
        cout << "Enter integers separated by spaces: ";
        getline(cin, line);

        size = traverseIntegers(line, arr);

        if (size == -1)
        {
            cout << "Invalid input. Please enter integers separated by spaces.\n";
            continue;
        }

        if (size == 0)
        {
            cout << "Please enter at least one integer.\n";
            continue;
        }

        return size;
    }
}

int getTargetInput()
{
    string input;

    while (true)
    {
        cout << "Enter the target value to search for: ";
        getline(cin, input);

        int target;
        bool isNegative = false;
        int startPos = 0;

        if (input.length() > 0 && input[0] == '-')
        {
            isNegative = true;
            startPos = 1;
        }

        if (startPos >= input.length())
        {
            cout << "Invalid input. Please enter an integer.\n";
            continue;
        }

        bool valid = true;
        target = 0;

        for (int i = startPos; i < input.length(); i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                target = target * 10 + (input[i] - '0');
            }
            else
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Invalid input. Please enter an integer.\n";
            continue;
        }

        return isNegative ? -target : target;
    }
}

void displayArray(const int arr[], int size, const string &label)
{
    cout << label << " [";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main()
{
    cout << "Insertion Sort and Binary Search" << endl;
    cout << "Enter the array elements:\n";

    int arr[MAX_SIZE];
    int originalArr[MAX_SIZE];

    int size = getArrayInput(arr);

    for (int i = 0; i < size; i++)
    {
        originalArr[i] = arr[i];
    }

    displayArray(originalArr, size, "Original Array:");

    insertionSort(arr, size);

    displayArray(arr, size, "Sorted Array:  ");

    int target = getTargetInput();

    int result = binarySearch(arr, size, target);

    cout << "\nSearching for " << target << " in the sorted array...\n";
    if (result != -1)
    {
        cout << "Element " << target << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << target << " is not present in the array" << endl;
    }

    return 0;
}