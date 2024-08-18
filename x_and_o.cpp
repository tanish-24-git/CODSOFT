#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE));
    initializeBoard(board);
    
    char currentPlayer = PLAYER_X;
    bool gameEnded = false;

    while (!gameEnded) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        
        int row, col;
        cin >> row >> col;

        if (isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;
            
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnded = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameEnded = true;
            } else {
                currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    cout<<"*************** welecome to x and o game **************";
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!" << endl;
    return 0;
}
