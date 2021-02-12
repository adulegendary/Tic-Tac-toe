/*
* Tic tac to game is below here.
* I make like 150 lines but i will reduce from 150 to 50 in the future.
*Game descrpition
* the game contain "X" and "O" players whith two players.
*"X" belongs to player 1 and "O" belongs to player 2.
* if one  player hold 3 of  diagonal,or horizental or vertical line thw player who hold it will win
* If not the match will tie or draw(i love soccer thats why i called draw. Draw means if two teams get equal point in one match it said draw)
* That it  is. We Will make some fetures in future for  the game thank you;

*/
#include <iostream>
using namespace std;
const int ROW = 3;
const int COLOMUN = 3;
char boards[ROW][COLOMUN] = { {'*','*','*'},{'*','*','*'},{'*','*','*'} };
char player1 = 'X';
string player2 = "Player 1";
int n;

void makeEqual(int& row, int& col) {
    cout << "put your row postion" << player2 << endl;
    cin >> row;
    cout << "now lets put the colomun postion" << player2 << endl;
    cin >> col;




    while (row < 0 || row >= 3) {
        cout << "please follow the instruction 0-2" << endl;
        cout << "put your row postion" << " " << player2 << endl;
        cin >> row;
        cout << "now lets put the colomun postion" << endl;
        cin >> col;
    }
    while (col < 0 || col >= 3) {
        cout << "please follow the instruction 0-2" << endl;
        cout << "put your row postion" << " " << player2 << endl;
        cin >> row;
        cout << "now lets put the colomun postion" << endl;
        cin >> col;
    }


    while (boards[row][col] != '*' || boards[row][col] != '*') {
        cout << "the postion is hold.Please change the postion of" << " " << player1 << endl;
        cout << "put your row postion" << " " << player2 << endl;
        cin >> row;
        cout << "now lets put the colomun postion" << " " << endl;
        cin >> col;
    }

    if (row == 0 && col == 0) {
        boards[0][0] = player1;
    }
    if (row == 0 && col == 1) {
        boards[0][1] = player1;
    }
    if (row == 0 && col == 2) {
        boards[0][2] = player1;
    }
    else if (row == 1 && col == 0) {
        boards[1][0] = player1;
    }
    else if (row == 1 && col == 1) {
        boards[1][1] = player1;
    }
    else if (row == 1 && col == 2) {
        boards[1][2] = player1;
    }
    else if (row == 2 && col == 0) {
        boards[2][0] = player1;
    }
    else if (row == 2 && col == 1) {
        boards[2][1] = player1;
    }
    else if (row == 2 && col == 2) {
        boards[2][2] = player1;

    }
}

// Chnage player function.

void changing() {
    if (player2 == "Player 2") {
        player2 = "Player 1";
    }
    else {
        player2 = "Player 2";
    }
}


// switching from x to o function.

void swichPlayer() {
    if (player1 == 'X') {
        player1 = 'O';
    }
    else {
        player1 = 'X';

    }

}


// Winning the game function.

int  winning() {
    for (int i = 0; i < 3; i++) {
        if (boards[i][0] == boards[i][1] && boards[i][1] == boards[i][2]) return boards[i][0];

        if (boards[0][i] == boards[1][i] && boards[1][i] == boards[2][i])return boards[0][i];


    }
    if (boards[0][0] == boards[1][1] && boards[1][1] == boards[2][2]) return boards[0][0];
    if (boards[0][2] == boards[1][1] && boards[1][1] == boards[2][0])return boards[0][2];

    return 0;

}

void tictoeboard() {
    cout << boards[0][0] << " " << boards[0][1] << " " << boards[0][2] << endl;
    cout << boards[1][0] << " " << boards[1][1] << " " << boards[1][2] << endl;
    cout << boards[2][0] << " " << boards[2][1] << " " << boards[2][2] << endl;
}


int main() {
    char board[ROW][COLOMUN];
    int row, col;
    cout << " Put your row and your colomun respectively " << endl;
    while (true) {

        n++;
        tictoeboard();
        makeEqual(row, col);
        swichPlayer();
        changing();
        if (winning() == 'X') {
            tictoeboard();
            cout << "x is winning Game Over.O is looser. " << endl;
            exit(0);
        }
        else if (winning() == 'O') {
            tictoeboard();
            cout << "O is winng Game over.X is looser" << endl;
            exit(0);
        }
        else if (winning() == 0 && n == 9) {
            tictoeboard();
            cout << "The Game is Draw no one win.Game Over" << endl;
            exit(0);
        }
        system("cls");
    }
    return 0;
}
//tic tac toe game