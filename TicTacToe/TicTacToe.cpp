#include <iostream>

using namespace std;

char value[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

void drawBoard()
{
    cout << "-----------" << endl;
    cout << " | " << " " << value[0] << " | " << value[1] << " | " << value[2] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << " " << value[3] << " | " << value[4] << " | " << value[5] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << " " << value[6] << " | " << value[7] << " | " << value[8] << " | " << endl;
    cout << "-----------" << endl;
}

// Function to check if the game is over
int logic()
{
    // check if player won verticaly
    for (int i = 0; i < 3; i++) { if (value[i] == value[i+1] && value[i+1] == value[i+2]) { return 1; } }
    // check if player won horizontaly
    for (int i = 0; i < 3; i++) { if (value[i] == value[i+3] && value[i+3] == value[i+6]) { return 1; } }
    // check if player won diagonally
    if (value[0] == value [4] && value[4] == value[8]) { return 1; }
    if (value[2] == value [4] && value[4] == value[6]) { return 1; }
    // check if there is a draw
    for (int i = 0; i < 9; i++)
    {
        if (value[i] != 'X' && value[i] != 'O') { return 0; }
    }
    return -1;
}

//  
int input(int &player, char &mark)
{
    int input;
    cout << "Pleayer number" << player <<" please enter a number from the board: ";
    cin >> input; 
    // check if input is valid
    if (input > 8 || input < 0) { cout << "The number is not on the board"; return 0; }
    // check if the input is already taken
    if (value[input] == 'X' || value[input] == 'O') { cout << "This slots is already occupied. Please choose another one"; return 0; }
    value[input] = mark;
    return input;
}

int main()
{
    int player = 1;

    while (logic() == 0)
    {
        // determine the mark 
        char mark = (player==1)? 'X' : 'O';
        drawBoard();
        input(player, mark);
        // Switch players after each turn
        if (player == 1) { player = 2; } else { player = 1; }
    }
    drawBoard();
    // check if there is a winner
    if (logic() == -1) { cout << "It's a draw!"; }
    else { cout << "Player " << player << " wins!"; }
    return 0;
}