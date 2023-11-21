#include <iostream>
#include <vector>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char> > &board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        vector<vector<char> > board(3, vector<char>(3, ' '));
        char currentPlayer = 'X';
        bool gameWon = false;
        bool draw = false;

        cout << "Tic-Tac-Toe game by: Pratham Aggarwal\n" << endl;

        while (!gameWon && !draw) {
            displayBoard(board);
            int row, col;

            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row;
            cin >> col;

            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
                board[row - 1][col - 1] = currentPlayer;

                if (checkWin(board, currentPlayer)) {
                    gameWon = true;
                    displayBoard(board);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                } else if (checkDraw(board)) {
                    draw = true;
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            } else {
                cout << "Invalid move. Please try again." << endl;
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}

