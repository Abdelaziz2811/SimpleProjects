#include <iostream>
#include <cstdlib>
using namespace std;

class clsTicTacToeGame {

private:
	char player = 'X';
	char computer = 'O';
	char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ', ' '};

	short ReadNumberInRange(short From, short To){

		short number;
		do {

			cout << "Enter a spot to place marker [1 to 9] ";
			cin >> number;

	 	} while (number < From || number > To);

		return number;
	}

public:
	void DrawBoard(){

	cout << "\n";
	cout << " _________________\n";
	cout << "|     |     |     |" << endl;
	cout << "|  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;
	cout << "|     |     |     |" << endl;
	cout << "|  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  |" << endl;
	cout << "|_____|_____|_____|" << endl;
	cout << "\n";
	}
		
	void PlayerMove(){

 	int number = 0;
	do {

		cout << "Enter a spot to place marker [1 to 9] ";
		number = ReadNumberInRange(1, 9);

		if(spaces[number - 1] == ' '){

			spaces[number - 1] = player;
			break;
		}

	} while (spaces[number - 1] != ' ');
	}

	void ComputerMove(){

	int number = 0;
	do {

		number = rand() % (9 - 1 + 1) + 1;

		if(spaces[number - 1] == ' '){

			spaces[number - 1] = computer;
			break;
		}

	} while (spaces[number - 1] != ' ');
	}

	bool CheckWinner(){

		char Winner;

		if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {

			spaces[0] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {

			spaces[3] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {

			spaces[6] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {

			spaces[0] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {

			spaces[1] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {

			spaces[2] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {

			spaces[0] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		}
		else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {

			spaces[2] == player ? cout << "You Won!\n" : cout << "You Lose!\n";
		} 
		else {

			return false;
		}

		return true;
	}

	bool CheckTie(){
		
		for (short i = 0; i < 9; i++){

			if (spaces[i] == ' '){

				return false;
			}
		}
		cout << "It's a Tie!";
		return true;
	}
};

int main() {
	srand((unsigned)time(NULL));

	clsTicTacToeGame StartGame;

	while (!StartGame.CheckWinner()) {

		StartGame.ComputerMove();
		StartGame.DrawBoard();

		if (StartGame.CheckTie() || StartGame.CheckWinner()) {

			break;
		}

		StartGame.PlayerMove();
		StartGame.DrawBoard();

	}

	return 0;
}