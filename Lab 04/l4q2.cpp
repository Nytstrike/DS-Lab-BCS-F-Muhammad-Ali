#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
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
    cout << "=== Bubble Sort Algorithm ===\n";
    cout << "Enter the array elements to sort:\n";

    int arr[MAX_SIZE];
    int originalArr[MAX_SIZE];

    int size = getArrayInput(arr);

    for (int i = 0; i < size; i++)
    {
        originalArr[i] = arr[i];
    }

    displayArray(originalArr, size, "Original Array:");

    bubbleSort(arr, size);

    displayArray(arr, size, "Sorted Array:  ");

    return 0;
}