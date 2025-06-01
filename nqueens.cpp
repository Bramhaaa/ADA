#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board, int N) {
    static int solutionCount = 1;
    cout << "Solution " << solutionCount++ << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;

    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        printSolution(board, N);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, N);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int N;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    solveNQueens(board, 0, N);

    return 0;
}
