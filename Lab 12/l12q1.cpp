#include <iostream>
#include <string>
using namespace std;

void bruteForceSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int comparisons = 0;
    cout << "Indices: ";
    bool first = true;
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
            comparisons++;
        }
        if (j < m)
        {
            comparisons++;
        }
        if (j == m)
        {
            if (!first)
            {
                cout << ", ";
            }
            cout << i;
            first = false;
        }
    }
    cout << "Total comparisons: " << comparisons << endl;
}

int main()
{
    string text = "testing the searching algorithm";
    string pattern = "search";
    bruteForceSearch(text, pattern);
    return 0;
}