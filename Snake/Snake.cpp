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
int score;
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup() 
{
    dir = STOP;
    y = height/2;
    x = width/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

//Function determining the position of snake head, fruit and score points during the game
void Draw() 
{
    system("cls"); 
    // Draw the ceiling
    for (int i = 0; i <= width+1; i++) 
        cout<< "#";
    cout<<endl;

    for ( int i = 0; i < height; i++)
    {
        for ( int j = 0; j < width; j++)
        {
            // Draw the left walls
            if (j == 0) cout<<"#"; 
            if (i == y && j == x) cout<<"0";
            else if (i == fruitY && j == fruitX) cout<<"F";         
            else
            {    
                bool print = false;
                //Draw the tail
                for ( int k = 0; k < nTail; k++) 
                {
                    
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout<< "o";
                        print = true;
                    }
                }
                if(!print) cout<<" ";
            }
            //Draw the right wall
            if (j == width-1) cout<<"#"; 
            
        }
        cout<<endl;
    }
    // Draw the floor
    for (int i = 0; i <= width+1; i++) cout<< "#"; 
    cout<<endl;
    cout << "Score:" << score << endl;
    cout << "To move press WASD" <<endl;

}
void Input()
{
    if (_kbhit()) // If a key is pressed
    {
        switch (_getch()) // Get the key pressed
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                GameOver = true;
                break;
        }
    }
}
void Logic()
{
    //Determining the position of the snake's tail
    int prevX = tailX[0];  
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y; 
    //Determining the position of snake's tail after it eats the fruit
    for ( int i = 1; i < nTail ; i++) 
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;

    }
    //Determining the position of the snake's head
    switch (dir) 
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

    //If snake hits the wall, game is over
    if (x >= width) x = 0; else if (x < 0) x = width - 1;  
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    
    for (int i = 0; i < nTail; i++) 
    //If snake hits it's tail, game is over
        {if (tailX[i] == x && tailY[i] == y) GameOver = true;}

    //If snake eats the fruit, it's tail grows and score increases
    if (x == fruitX && y == fruitY) 
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
