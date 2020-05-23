#include"GameLogic.h"

/*TODO LIST
>> Stop players to not overwrite each others position 
>> Allow players to choose how many round they want 
>> Play against AI(<<)
*/
void Tictactoe::ShowCurrentBoard() {
	for (int x{ 0 }; x < 3; x++) {
		for (int y{ 0 }; y < 3; y++) {
			std::cout << gameboard[x][y]<<"\t|";
			if (y == 2) {
				std::cout << "\n-----\t-----\t----- \n";
			}
		}
	}
	std::cout << "\n-------------------------------\n";

}
//THINKING HOW I DETERMINE IF PLAYER 1 WINS OR PLAYER 2
bool Tictactoe::GameBoardLogic(std::string _player1) {
	if (gameboard[0][0] == _player1 && gameboard[0][1] == _player1 & gameboard[0][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[1][0] == _player1 && gameboard[1][1] == _player1 & gameboard[1][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[2][0] == _player1 && gameboard[2][1] == _player1 & gameboard[2][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[0][0] == _player1 && gameboard[1][1] == _player1 & gameboard[2][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[0][2] == _player1 && gameboard[1][1] == _player1 & gameboard[2][0] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[0][0] == _player1 && gameboard[1][0] == _player1 & gameboard[2][0] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[0][1] == _player1 && gameboard[1][1] == _player1 & gameboard[2][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	else if (gameboard[0][2] == _player1 && gameboard[1][2] == _player1 & gameboard[2][2] == _player1) {
		if (_player1 == "X") {
			Player1Wins();
			return true;
		}
		else {
			Player2Wins();
			return true;
		}
	}
	

	return false; 
} 
//----------------All the tictactoe logic  above-------------------

void Tictactoe::DeterminePickLogicPlayer1() {
	switch (player1option)
	{
	case 1:
		gameboard[0][0] = "X";
		break;
	case 2:
		gameboard[0][1] = "X";
		break;
	case 3:
		gameboard[0][2] = "X";
		break;
	case 4:
		gameboard[1][0] = "X";
		break;
	case 5:
		gameboard[1][1] = "X";
		break;
	case 6:
		gameboard[1][2] = "X";
		break;
	case 7:
		gameboard[2][0] = "X";
		break;
	case 8:
		gameboard[2][1] = "X";
		break;
	case 9:
		gameboard[2][2] = "X";
		break;
	
	}
}
void Tictactoe::DeterminePickLogicPlayer2() {
	switch (player2option)
	{
	case 1:
		gameboard[0][0] = "O";
		break;
	case 2:
		gameboard[0][1] = "O";
		break;
	case 3:
		gameboard[0][2] = "O";
		break;
	case 4:
		gameboard[1][0] = "O";
		break;
	case 5:
		gameboard[1][1] = "O";
		break;
	case 6:
		gameboard[1][2] = "O";
		break;
	case 7:
		gameboard[2][0] = "O";
		break;
	case 8:
		gameboard[2][1] = "O";
		break;
	case 9:
		gameboard[2][2] = "O";
		break;

	}
}

void Tictactoe::Player1Wins() {
	std::cout << "Player 1 has won\n";
}

void Tictactoe::Player2Wins() {
	std::cout << "Player 2 has won\n";
}


void Tictactoe::PlayerTurns() {
	while (amountofturns != 9) {
		amountofturns++;
		std::cout << "Player1 turn: "; std::cin >> player1option;
		DeterminePickLogicPlayer1();//Determines what the player picks
		ShowCurrentBoard();
		if (GameBoardLogic("X") == true) {
			amountofturns = 9;
			break;
		}
		std::cout << "Player2 turn: "; std::cin >> player2option;
		DeterminePickLogicPlayer2();
		ShowCurrentBoard(); 
		if (GameBoardLogic("O") == true) {
			amountofturns = 9;
			break;
		}
	}
}

void Tictactoe::StartGame() {
	ShowCurrentBoard();
	PlayerTurns();//Allows the players to pick which position they would like to go
	
}
