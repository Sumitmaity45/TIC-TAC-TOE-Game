#include <iostream>
using namespace std;
// Array for the Game board
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// Variable declaration
string n1 = "", n2 = "";
int row, col;
char token = 'X';
bool tied = false;
// Function to show the current status of the game board
void function1()
{
    // Create the board-structure
    cout<<" "<<space[0][0]<<"  |"<<" "<<space[0][1]<<"  |"<<" "<<space[0][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<" "<<space[1][0]<<"  |"<<" "<<space[1][1]<<"  |"<<" "<<space[1][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<" "<<space[2][0]<<"  |"<<" "<<space[2][1]<<"  |"<<" "<<space[2][2]<<" "<<endl;
    cout<<"    |    |    "<<endl;
}
// Function to get the player input and update the board
void function2()
{
m:
    int digit;
    if (token == 'X')
    {
        cout << n1 << " please enter: ";
        cin >> digit;
    }
    if (token == 'O')
    {
        cout << n2 << " please enter: ";
        cin >> digit;
    }
// Taking input from the user and updating the board according to choice and reassigning the token start
    if (digit == 1)
    {
        row = 0;
        col = 0;
    }
    else if (digit == 2)
    {
        row = 0;
        col = 1;
    }
    else if (digit == 3)
    {
        row = 0;
        col = 2;
    }
    else if (digit == 4)
    {
        row = 1;
        col = 0;
    }
    else if (digit == 5)
    {
        row = 1;
        col = 1;
    }
    else if (digit == 6)
    {
        row = 1;
        col = 2;
    }
    else if (digit == 7)
    {
        row = 2;
        col = 0;
    }
    else if (digit == 8)
    {
        row = 2;
        col = 1;
    }
    else if (digit == 9)
    {
        row = 2;
        col = 2;
    }
    else
    {
        cout << "Invalid move...!!!" << endl;
        goto m;
    }

    if (token == 'X' && space[row][col] != 'X' && space[row][col] != 'O')
    {
        // Updating the position for X symbol if it is not already occupied
        space[row][col] = 'X';
        token = 'O';
    }
    else if (token == 'O' && space[row][col] != 'X' && space[row][col] != 'O')
    {
        // Updating the position for O symbol if it is not already occupied
        space[row][col] = 'O';
        token = 'X';
    }
    else
    {
        // If input position is already filled
        cout << "Box already filled ! Please choose another...!!" << endl;
        goto m;
    }
}
// Matching function
bool function3()
{
    // For horizontally and vertically matching
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
            return true;
    }
    // For diagonally matching
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }
    // Whether the game is still going on or finished

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'X' && space[i][j] != 'O')
            {
                return false;
            }
        }
    }
    tied = true;
    return true;
}

int main()
{
    cout<<"\t\t\tTIC -- TAC -- TOE -- GAME\t\t\t"<<endl;
    cout<<"\t\t\t\tFOR 2 PLAYERS\t\t\t"<<endl;
    cout<<"\t\t\tPLAYER - 1 [X]    PLAYER - 2 [O]\t"<<endl;
    cout << "Enter the name of first player: " << endl;
    getline(cin, n1);
    cout << "Enter the name of second player: " << endl;
    getline(cin, n2);
    cout << n1 << " is palyer1 so he/she will play first" << endl;
    cout << n2 << " is palyer2 so he/she will play second" << endl;
    while (!function3())
    {
        function1();
        function2();
        function3();
    }
    function1();
// Game result
    if (tied == true)
    {
        cout << "Unfortunately, It's a draw" << endl;
    }
    else if (token == 'X' && tied == false)
    {
        cout<<"Congratulation " << n2 << ", you win the game...!!" << endl;
    }
    else if (token == 'O' && tied == false)
    {
        cout<<"Congratulation " << n1 << ", you win the game...!!" << endl;
    }
    return 0;
}