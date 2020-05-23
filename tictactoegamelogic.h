#pragma once

#include<iostream>

class Tictactoe {

private:
	bool GameBoardLogic(std::string _player1);
	void ShowCurrentBoard();
	void DeterminePickLogicPlayer1();
	void DeterminePickLogicPlayer2();
	int  player1option;
	int  player2option;
	void PlayerTurns();
	void Player1Wins();
	void Player2Wins();
	int amountofturns{ 0 };
	bool player1{ false }, player2{ false };
	std::string gameboard[3][3]{ {{ "1"  }, {"2" }, { "3"  } },
								 {{ "4" }, { "5" }, { "6" } },
								{ { "7" }, { "8" }, { "9" } }	}; // This is just for my refrence dw

	
	
	
public:
	void StartGame();
	
	



};
