#include <iostream>
using namespace std;

const int SIZE = 9;

bool is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
    // Checking row
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == num)
            return false;
    }

    // Checking column
    for (int j = 0; j < SIZE; j++)
    {
        if (grid[j][col] == num)
            return false;
    }

    // Checking 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool sol_sudoku(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (is_valid(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if (sol_sudoku(grid))
                            return true;

                        // backtracking
                        grid[row][col] = 0;
                    }
                }
                // trigger backtracking
                return false;
            }
        }
    }
    // solved
    return true;
}

void printGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " | ";
        }
        cout <<"\n" <<endl;
    }
}

int main()
{
    int grid[SIZE][SIZE] =
        {
            {0, 0, 0, 2, 6, 0, 7, 0, 1},
            {6, 8, 0, 0, 7, 0, 0, 9, 0},
            {1, 9, 0, 0, 0, 4, 5, 0, 0},
            {8, 2, 0, 1, 0, 0, 0, 4, 0},
            {0, 0, 4, 6, 0, 2, 9, 0, 0},
            {0, 5, 0, 0, 0, 3, 0, 2, 8},
            {0, 0, 9, 3, 0, 0, 0, 7, 4},
            {0, 4, 0, 0, 5, 0, 0, 3, 6},
            {7, 0, 3, 0, 1, 8, 0, 0, 0}};

    cout << "Initial Sudoku Puzzle:\n";
    printGrid(grid);

    if (sol_sudoku(grid))
    {
        cout << "\nSolved Sudoku Puzzle:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No valid solution exists for this puzzle." << endl;
    }

    return 0;
}
