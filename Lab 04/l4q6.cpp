#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

int getNextGap(int gap)
{
    gap = (gap * 10) / 13;
    if (gap < 1)
    {
        return 1;
    }
    return gap;
}

void combSort(int arr[], int n, int &swapCount, int &comparisonCount)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped)
    {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++)
        {
            comparisonCount++;
            if (arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
                swapCount++;
            }
        }
    }
}

int parseIntegers(const string &input, int arr[])
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

        size = parseIntegers(line, arr);

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
    cout << "Comb Sort Algorithm" << endl;

    int arr[MAX_SIZE];
    int originalArr[MAX_SIZE];

    int size = getArrayInput(arr);

    for (int i = 0; i < size; i++)
    {
        originalArr[i] = arr[i];
    }

    displayArray(originalArr, size, "Original Array:");

    int swapCount = 0;
    int comparisonCount = 0;

    combSort(arr, size, swapCount, comparisonCount);

    displayArray(arr, size, "Sorted Array:  ");

    cout << "\n=== Complexity Analysis ===\n";
    cout << "Total Comparisons: " << comparisonCount << endl;
    cout << "Total Swaps: " << swapCount << endl;
    cout << "Array Size: " << size << endl;

    return 0;
}