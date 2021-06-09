#include <iostream>
using namespace std;

string board[9] = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};

void displayBoard() {
    cout << "   " << endl;
    cout << board[0] << " | " << board[1] << " | " << board[2] << "     " << "1" << " | " << "2" << " | " << "3" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << "     " << "4" << " | " << "5" << " | " << "6" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << "     " << "7" << " | " << "8" << " | " << "9" << endl;
    cout << "   " << endl;
}

int main() {
    int chance = 0;
    int move; 

    cout << "Welcome to Tic Tac Toe! Player one plays 'x' and player two plays 'o'." << endl;

    while (true) {
        displayBoard();

        bool isItAvailable = false;

        for (int i = 0; i < 9; i++)
        {
            if (board[i] == "_") {
                isItAvailable = true;
                break;
            }
        }

        if (isItAvailable != true) {
            cout << "It's a tie." << endl;
            break;
        }

        if (chance == 0) {
            cout << "It's player one's chance." << endl;
            cout << "Make a move: ";
            cin >> move;
            move = move - 1;

            if (board[move] != "_") {
                cout << "This box is already taken. Try again!" << endl;
                continue;
            }

            board[move] = "x";
            chance += 1;

            if ((board[0] + board[1] + board[2] == "xxx") or (board[3] + board[4] + board[5] == "xxx") or (board[6] + board[7] + board[8] == "xxx") or (board[0] + board[3] + board[6] == "xxx") or (board[1] + board[4] + board[7] == "xxx") or (board[2] + board[5] + board[8] == "xxx") or (board[0] + board[4] + board[8] == "xxx") or (board[2] + board[4] + board[6] == "xxx")) {
                displayBoard();
                cout << "Player one wins!" << endl;
                break;
            }
        }
        else
        {
            cout << "It's player two's chance" << endl;
            cout << "Make a move: ";
            cin >> move;
            move = move - 1;

            if (board[move] != "_") {
                cout << "This box is already taken. Try again!" << endl;
                continue;
            }

            board[move] = "o";
            chance -= 1;

            if ((board[0] + board[1] + board[2] == "ooo") or (board[3] + board[4] + board[5] == "ooo") or (board[6] + board[7] + board[8] == "ooo") or (board[0] + board[3] + board[6] == "ooo") or (board[1] + board[4] + board[7] == "ooo") or (board[2] + board[5] + board[8] == "ooo") or (board[0] + board[4] + board[8] == "ooo") or (board[2] + board[4] + board[6] == "ooo")) {
                displayBoard();
                cout << "Player two wins!" << endl;
                break;
            }
        }
    }
    return 0;
}