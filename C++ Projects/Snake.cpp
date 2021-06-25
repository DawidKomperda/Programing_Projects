// Simple snake game in console with option to keep your highest score

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

bool GameOver;

const int height = 20;
const int width = 20;
int x,y,fruitY,fruitX;
int tailX[100], tailY[100];
int nTail;
// fstream Ranking("Ranking2.txt");
// int HighestScore,RankingS,
int score;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup() //Function determining the position of snake head, fruit and score points at the start of the game 
{
//     while (Ranking>>RankingS) HighestScore=RankingS;
    dir = STOP;
    y = height/2;
    x = width/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;

}

void Draw() //Function will create and display the game enviroment together with current score. It draws the boards, as well as the player and the fruit. 
{
    system("cls"); 
    for (int i = 0; i <= width+1; i++) // Draw the ceiling
        cout<< "#";
    cout<<endl;

    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            if (j == 0) cout<<"#"; //Draw the left wall
            if (i == y && j == x) cout<<"0";
            
            else if (i == fruitY && j == fruitX) cout<<"F";
            
            else
            {    
                bool print = false;
                for ( int k = 0; k < nTail; k++) // Draw the tail of the snake
                {
                    
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout<< "o";
                        print = true;
                    }
                }
                if(!print) cout<<" ";

            }
            if (j == width-1) cout<<"#"; // Draw the right wall
            
        }
        cout<<endl;
    }

    for (int i = 0; i <= width+1; i++) cout<< "#"; // Draw the floor
    cout<<endl;
    
    cout << "Score:" << score << endl;
//     cout << "Highest Score:" << HighestScore << endl;
//     if(score > HighestScore) Ranking << score;
//     Ranking.close();

}
void Input()
{
    if(_kbhit()) //Getting input from the user to determine the drection in which snake will move
    {
        switch(_getch())
        {
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                GameOver=true;
                break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];  //Determining the position of the snake's tail
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y; 
    for ( int i = 1; i < nTail ; i++) //Determining the position of snake's tail units by getting the position of previous unit
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;

    }
    switch (dir) //Movement of the snake on the board
    {
    case UP:
        y--;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x >= width) x = 0; else if (x < 0) x = width - 1;  //If the snake's coordinates are equal to or greater than the border, the snake will be transported to the opposite end
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    
    for (int i = 0; i < nTail; i++) //
        if (tailX[i] == x && tailY[i] == y) // If the position of the snake's head is equal to the position of its tail, the game will be over
            GameOver = true;
    
    if (x == fruitX && y == fruitY) //If the snake head position is equal to the fruit position player will score 10 points and the fruit position should appear in new randomly determinated place on the board
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

}

int main()
{   
    Setup();
    while(!GameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10);
    }
    return 0;  
}
