#include <iostream>
using namespace std;

void findEqualSumPairs(int arr[], int n)
{
    int sums[1000];
    int pairs[1000][2];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int currentSum = arr[i] + arr[j];
            for (int k = 0; k < count; k++)
            {
                if (sums[k] == currentSum)
                {
                    int a = pairs[k][0];
                    int b = pairs[k][1];
                    int c = arr[i];
                    int d = arr[j];
                    if (a != c && a != d && b != c && b != d)
                    {
                        cout << "(" << a << ", " << b << ") and (" << c << ", " << d << ")";
                        return;
                    }
                }
            }
            sums[count] = currentSum;
            pairs[count][0] = arr[i];
            pairs[count][1] = arr[j];
            count++;
        }
    }
    cout << "No pairs found";
}

int main()
{
    int test1[] = {3, 4, 7, 1, 2, 9, 8};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    int test2[] = {3, 4, 7, 1, 12, 9};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    int test3[] = {65, 30, 7, 90, 1, 9, 8};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    cout << "Test 1: ";
    findEqualSumPairs(test1, size1);
    cout << endl;
    cout << "Test 2: ";
    findEqualSumPairs(test2, size2);
    cout << endl;
    cout << "Test 3: ";
    findEqualSumPairs(test3, size3);
    cout << endl;
    return 0;
}