#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Player::Player()
{
	pSymbol = ' ';

}

Player::Player(const Player& p)
{
	pSymbol = p.pSymbol;
}

Player::~Player()
{

}


char Player::getInput() const
{
	return pSymbol;
}

void Player::setInput(char Char)
{
	pSymbol = Char;
}

PlayerHuman::PlayerHuman()
	:Player()
{

}

PlayerHuman::PlayerHuman(const PlayerHuman& pp)
	: Player(pp)
{

}

PlayerHuman PlayerHuman::operator=(const PlayerHuman& p)
{
	if (&p != this)
		setInput(p.getInput());

	return *this;
}

PlayerHuman::~PlayerHuman()
{

}

Position PlayerHuman::nextMove(const Board& board)
{
	Position pos;
	board.print();
	cout << "Enter the position to place a symbol: ";
	cin >> pos.row;
	cin >> pos.column;
	cout << endl;
	while (!isValid(board, pos))
	{
		cout << "Invalid choice";
		cout << "\nEnter the position to place a symbol: ";
		cin >> pos.row;
		cin >> pos.column;
	}

	return pos;
}

bool PlayerHuman::isValid(const Board& board, const Position& pos) const
{
	if (pos.row >= 0 && pos.row < ROW_NUM && pos.column >= 0 && pos.column < COL_NUM)
		if (board.Empty(pos))
			return true;

	return false;
}

PlayerRandom::PlayerRandom()
	:Player()
{

}

PlayerRandom::PlayerRandom(const PlayerRandom& ppp)
	: Player(ppp)
{

}

PlayerRandom PlayerRandom::operator=(const PlayerRandom& p)
{
	if (&p != this)
		setInput(p.getInput());

	return *this;
}

PlayerRandom:: ~PlayerRandom()
{

}

Position PlayerRandom::nextMove(const Board& board)
{
	board.print();

	Position pos;
	srand((unsigned)time(0));
	do
	{

		pos.row = rand() % 3;
		pos.column = rand() % 3;

	} while (!isValid(board, pos));

	return pos;
}

bool PlayerRandom::isValid(const Board& board, const Position& pos) const
{
	if (pos.row >= 0 && pos.row < ROW_NUM && pos.column >= 0 && pos.column < COL_NUM)
		if (board.Empty(pos))
			return true;

	return false;
}