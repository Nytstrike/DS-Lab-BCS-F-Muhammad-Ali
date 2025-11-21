#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner a[], int beg, int mid, int end) {
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    Runner* Left = new Runner[n1];
    Runner* Right = new Runner[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = a[beg + i];

    for (int j = 0; j < n2; j++)
        Right[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = beg;

    while (i < n1 && j < n2) {
        if (Left[i].time <= Right[j].time) {
            a[k++] = Left[i++];
        } else {
            a[k++] = Right[j++];
        }
    }

    while (i < n1) {
        a[k++] = Left[i++];
    }

    while (j < n2) {
        a[k++] = Right[j++];
    }

    delete[] Left;
    delete[] Right;
}

void mergeSort(Runner a[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

int main() {
    const int N = 10;
    Runner runners[N];

    cout << "Enter name and finish time for runner 1: ";
    cin >> runners[0].name >> runners[0].time;

    for (int i = 1; i < N; i++) {
        cout << "Enter name and finish time for runner " << i + 1 << ": ";
        cin >> runners[i].name >> runners[i].time;
    }

    mergeSort(runners, 0, N - 1);

    cout << "Top 5 fastest runners:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << runners[i].name
             << " - " << runners[i].time << " seconds\n";
    }

    return 0;
}
