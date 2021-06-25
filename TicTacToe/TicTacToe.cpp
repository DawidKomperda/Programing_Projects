#include <iostream>
#include <conio.h>

using namespace std;

int turn = 0; //Select which player will start the game 0 for player 1, 1 for player 2
char icon; //Character that will represent players
int input;

int logic();
int placeIcon();
void Instruction();
void DrawBoard();

char board[3][3] = 
{
	'-','-','-',
	'-','-','-',
	'-','-','-'
};

int logic()
{
	//checking if the same character appears three times in the same row
	if(board[0][0]==icon && board[0][1]==icon && board[0][2]==icon)return true;
	if(board[1][0]==icon && board[1][1]==icon && board[1][2]==icon)return true;
	if(board[2][0]==icon && board[2][1]==icon && board[2][2]==icon)return true;
	
	//checking if the same character appears three times in the same colum
	if(board[0][0]==icon && board[1][0]==icon && board[2][0]==icon)return true;
	if(board[0][1]==icon && board[1][1]==icon && board[2][1]==icon)return true;
	if(board[0][2]==icon && board[1][2]==icon && board[2][2]==icon)return true;
	
	//checking if the same character appears three times in the same diagonal
	if(board[0][0]==icon && board[1][1]==icon && board[2][2]==icon)return true;
	if(board[0][2]==icon && board[1][1]==icon && board[2][0]==icon)return true;
	
	return false;
}

int placeIcon() //loop through two-dimensionall array until it finds input, then place icon in the correct place, otherwise assume the place is taken
{
	for(int i=0,k=1; i<3; i++) 
    {
		for(int j=0; j<3; j++,k++)
        {
			if( k==input )
				if(board[i][j] == '-') //Placeing the icon insite the 
                {
					board[i][j] = icon;
					return 1;
				}
				else
                {
					cout<<"This slot is already taken";
					getch();
					return 0;
				}
		}
	}
}

void Instruction()
{
	cout<<endl<<endl<<"Enter the number you want your icon to be"<<endl;
    	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" 1 | 2 | 3 "<<endl;
	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" 4 | 5 | 6 "<<endl;
	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" 7 | 8 | 9 "<<endl;
    	cout<<"~~~~~~~~~~~~"<<endl;
}

void DrawBoard()  //Draw the board with coordinates of the icons
{
    	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
	cout<<"~~~~~~~~~~~~"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
   	cout<<"~~~~~~~~~~~~"<<endl;
}

void players()
{
	bool won = false;
	int validInput = 0;

	for(int i=0; i<9; i++) //loop for number of slots in the game, in this case 9
    {
		system("cls");
		DrawBoard();  //Draw the board
		if(turn) cout<<"Player 1 Turn (Symbol: O)"<<endl;
		else cout<<"Player 2 Turn (Symbol: X)"<<endl;
		Instruction(); //Draw the instruction
		cout<<"Enter Input: ";
		cin>>input;
		while(input<0 || input>9) //Check if user input is within the board
        	{
			cout<<"Wrong input, please try again ";
			cin>>input;
		}
		if(turn) icon = 'O';
		else icon = 'X';
		validInput = placeIcon(); 
		if( !validInput )
		{
			i--;
			continue;
		}
		won = logic(); //If either outcome of the checking is true one of the players won
		if( won)
		{
			system("cls");
			DrawBoard();
			if(turn) cout<<endl<<"Player 1 Won";
			else cout<<endl<<"Pleayer 2 Won";
			getch();
			break;
		}
		if(i==8)//Otherwise its a draw
		{
			system("cls");
			DrawBoard();
			cout<<endl<<"Draw";
		}
		turn = !turn; //Changing the turns, (switch betwen 1 and 0 )
	}
}


int main()
{
	players();

	return 0;
}
