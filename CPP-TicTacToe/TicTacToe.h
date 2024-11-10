#pragma once

#include <iostream>

#include "Game.h"

class TicTacToe : public Game
{

private:

	int m_currentPlayer = 0;

	char m_piece;

	char m_board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };

	int m_turn = 0;

public:

	bool IsGameOver() const;

	void TakeTurn();

	void Display() const;

};