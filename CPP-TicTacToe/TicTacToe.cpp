
#include "TicTacToe.h"

bool TicTacToe::IsGameOver() const
{
	if ((m_board[0] == m_piece && m_board[1] == m_piece && m_board[2] == m_piece) // row 1
	|| (m_board[3] == m_piece && m_board[4] == m_piece && m_board[5] == m_piece) // row 2
	|| (m_board[6] == m_piece && m_board[7] == m_piece && m_board[8] == m_piece) // row 3
	|| (m_board[0] == m_piece && m_board[3] == m_piece && m_board[6] == m_piece) // column 1
	|| (m_board[1] == m_piece && m_board[4] == m_piece && m_board[7] == m_piece) // column 2
	|| (m_board[2] == m_piece && m_board[5] == m_piece && m_board[8] == m_piece) // column 3
	|| (m_board[0] == m_piece && m_board[4] == m_piece && m_board[8] == m_piece) // diagonal 1
	|| (m_board[2] == m_piece && m_board[4] == m_piece && m_board[6] == m_piece)) // diagonal 2
	{
		if (m_piece == 'x') std::cout << "Player 1 wins!\n\n";
		if (m_piece == 'o') std::cout << "Player 2 wins!\n\n";
		return true;
	}
	else if (m_turn == 9) // tie
	{
		std::cout << "Tie!\n\n";
		return true;
	}
	else return false; // game not over
}

void TicTacToe::TakeTurn()
{
	if (m_currentPlayer == 0)
	{
		m_piece = 'x';
		std::cout << "Player 1 (x)\n";
	}

	if (m_currentPlayer == 1)
	{
		m_piece = 'o';
		std::cout << "Player 2 (o)\n";
	}

	int place = 0;
	while (place < 1 || place > 9)
	{
		std::cout << "In which spot do you want to place your piece? (1-9): ";
		std::cin >> place;

		while ((place >= 1 && place <= 9) && (m_board[place - 1] == 'x' || m_board[place - 1] == 'o'))
		{
			std::cout << "Your piece must be placed in empty spot. In which spot do you want to place your piece? (1-9): ";
			std::cin >> place;
		}
	}
	m_board[place - 1] = m_piece;

	m_turn++;

	if (m_currentPlayer == 0) m_currentPlayer = 1;
	else m_currentPlayer = 0;
}

void TicTacToe::Display() const
{
	system("cls");
	std::cout << "\n " << m_board[0] << " | " << m_board[1] << " | " << m_board[2] << " \n";
	std::cout << "-----------\n";
	std::cout << " " << m_board[3] << " | " << m_board[4] << " | " << m_board[5] << " \n";
	std::cout << "-----------\n";
	std::cout << " " << m_board[6] << " | " << m_board[7] << " | " << m_board[8] << "\n\n";
}