#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void print_board(const vector<vector<string>>& board);
bool check_win(const vector<vector<string>>& board, const string& player);
bool check_draw(const vector<vector<string>>& board);
bool is_valid_move(int row, int col, const vector<vector<string>>& board);
void play_game();

int main() {
    char play_again;
    do {
        play_game();
        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');
    
    return 0;
}

void print_board(const vector<vector<string>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool check_win(const vector<vector<string>>& board, const string& player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

bool check_draw(const vector<vector<string>>& board) {
    // Check if the board is full (no empty spaces left)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == " ")
                return false;
        }
    }
    return true;
}

bool is_valid_move(int row, int col, const vector<vector<string>>& board) {
    // Check if the cell is empty and within bounds
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == " ");
}

void play_game() {
    vector<vector<string>> board(3, vector<string>(3, " "));
    string current_player = "X";
    bool game_over = false;
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X, Player 2: O" << endl;

    while (!game_over) {
        print_board(board);
        
        // Get move from current player
        cout << "Player " << current_player << ", enter your move (row[1-3] col[1-3]): ";
        cin >> row >> col;
        row--; // Adjust to zero-indexed
        col--; // Adjust to zero-indexed
        
        // Validate the move
        if (!is_valid_move(row, col, board)) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }
        
        // Make the move
        board[row][col] = current_player;

        // Check if the current player wins
        if (check_win(board, current_player)) {
            print_board(board);
            cout << "Player " << current_player << " wins! Congratulations!" << endl;
            game_over = true;
        } else if (check_draw(board)) {
            print_board(board);
            cout << "It's a draw!" << endl;
            game_over = true;
        } else {
            // Switch to the other player
            current_player = (current_player == "X") ? "O" : "X";
        }
    }
}

