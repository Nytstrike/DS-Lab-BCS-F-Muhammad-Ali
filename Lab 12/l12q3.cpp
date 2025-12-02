#include <iostream>
#include <string>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(const string &pattern, int badChar[])
{
    int m = pattern.length();
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

void goodSuffixHeuristic(const string &pattern, int goodSuffix[])
{
    int m = pattern.length();
    int *borderPos= new int [m + 1];

    for (int i = 0; i <= m; i++)
    {
        goodSuffix[i] = 0;
        borderPos[i] = 0;
    }
    int i = m, j = m + 1;
    borderPos[i] = j;
    while (i > 0)
    {
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            if (goodSuffix[j] == 0)
                goodSuffix[j] = j - i;
            j = borderPos[j];
        }
        i--;
        j--;
        borderPos[i] = j;
    }
    j = borderPos[0];
    for (i = 0; i <= m; i++)
    {
        if (goodSuffix[i] == 0)
        {
            goodSuffix[i] = j;
        }
        if (i == j)
        {
            j = borderPos[j];
        }
    }
}

void boyerMooreSearch(const string &text, const string &pattern)
{
    int n, m;
    n = text.length();
    m = pattern.length();

    int badChar[NO_OF_CHARS];
    int *goodSuffix = new int [m+1];
    badCharHeuristic(pattern, badChar);
    goodSuffixHeuristic(pattern, goodSuffix);
    bool first = true;
    cout << "Output: [";

    int s = 0;
    while (s <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            if (!first)
            {
                cout << ", ";
            }
            cout << s;
            first = false;
            s += goodSuffix[0];
        }
        else
        {
            int badCharShift = max(1, j - badChar[text[s + j]]);
            int goodSuffixShift = goodSuffix[j + 1];
            s += max(badCharShift, goodSuffixShift);
        }
    }

    cout << "]" << endl;
}

int main()
{
    string DNA = "ACGTACGTGACG";
    string pattern = "ACG";

    boyerMooreSearch(DNA, pattern);

    return 0;
}