#include <iostream>
using namespace std;

int** allocating(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++) {
        m[i] = new int[c];
    }
    return m;
}

void deallocating(int** m, int r) {
    for (int i = 0; i < r; i++) {
        delete[] m[i];
    }
    delete[] m;
}

void read(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }
}

void display(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

int** operate(int** X, int** Y, int r, int c, bool add) {
    int** Z = allocating(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Z[i][j] = add ? X[i][j] + Y[i][j] : X[i][j] - Y[i][j];
        }
    }
    return Z;
}

int main() {
    int r, c;
    cin >> r >> c;

    int** A = allocating(r, c);
    int** B = allocating(r, c);

    read(A, r, c);
    read(B, r, c);

    int** S = operate(A, B, r, c, true);
    int** D = operate(A, B, r, c, false);

    display(S, r, c);
    display(D, r, c);

    deallocating(A, r);
    deallocating(B, r);
    deallocating(S, r);
    deallocating(D, r);

    return 0;
}
