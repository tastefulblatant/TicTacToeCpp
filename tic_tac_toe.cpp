#include <iostream>
#include <ctime>

void DrawBoard(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);
bool CheckWinner(char *spaces, char player, char computer);
bool CheckTie(char *spaces);

int main()
{
    char spaces [9] = {' ', ' ', ' ',' ', ' ', ' ',' ', ' ', ' '};
	char player = 'X';
	char computer = 'O';
	bool running = true;

	DrawBoard(spaces);

	while(running){
		PlayerMove(spaces, player);
		DrawBoard(spaces);

		if(CheckWinner(spaces, player, computer)){
			running = false;
			
		}
		else if(CheckTie(spaces)){
			running = false;
			
		}

		ComputerMove(spaces, computer);
		DrawBoard(spaces);
		if(CheckWinner(spaces, player, computer)){
			running = false;
		}
		else if(CheckTie(spaces)){
			running = false;
		}
	}
	std::cout << "Thank's for playing!\n";
	return 0;
}

void DrawBoard(char *spaces){
	std::cout << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[0] <<"  | " << spaces[1] << "   |  " << spaces[2] << "  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[3]<< "  | " << spaces[4] << "   |  " << spaces[5] << "  " << '\n';
	std::cout << "_____|_____|_____" << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << "  " << spaces[6]<< "  | " << spaces[7] << "   |  " << spaces[8] << "  " << '\n';
	std::cout << "     |     |     " << '\n';
	std::cout << '\n';

}
void PlayerMove(char *spaces, char player)
{
	int number;

	do{
		std::cout << "Enter a spot to place a marker (1-9) ";
		std::cin >> number;
		number--;
		if (spaces[number] == ' ')
		{
			spaces[number] = player;
			break;
		}
		
	}while(!number > 0 || !number < 8);
}
void ComputerMove(char *spaces, char computer)
{
	int number;
	srand(time(NULL));
	while (true)
	{
		number = rand() % 9;
		if (spaces[number] == ' ')
		{
			spaces[number] = computer;
			break;
		}
		
	}
	
}
bool CheckWinner(char *spaces, char player, char computer)
{
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
	{
		spaces[0] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}

	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
	{
		spaces[3] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
	{
		spaces[6] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
	{
		spaces[0] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
	{
		spaces[1] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
	{
		spaces[2] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
	{
		spaces[0] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
	{
		spaces[2] == player ? std::cout << "YOU WON!\n" : std::cout << "YOU LOSE!\n";
	}
	else{
		return false;
	}
	return true;
}
bool CheckTie(char *spaces)
{	
	for (int i = 0; i < 9; i++)
	{
		if (spaces[i] == ' ')
		{
			return false;
		}
	}
	std::cout << "IT'S A TIE!\n";
	return true;
}