#include <iostream>
using namespace std;
#include "Board.h"


Board::Board()
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
			array[i][j] = ' ';
	}
}

Board::Board(const Board& to_copy)
{
	copy(to_copy);
}

Board::~Board()
{

}

void Board::copy(const Board& to_copy)
{
	position.row = to_copy.position.row;
	position.column = to_copy.position.column;

	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
			array[i][j] = to_copy.array[i][j];
	}

}

Board Board::operator=(const Board& to_copy)
{
	if (&to_copy != this)
		copy(to_copy);
	
	return *this;
}

char Board::getSymbol(Position pos) const
{
	return array[pos.row][pos.column];
}

void Board::setSymbol(Position pos, char symbol)
{
	array[pos.row][pos.column] = symbol;
}

//bool isWithinGrid() const;
void Board::print() const
{
	cout << "+-- +-- +-- +";

	for (int i = 0; i < ROW_NUM; i++)
	{
		cout << "\n| ";

		for (int j = 0; j < COL_NUM; j++)
			cout << array[i][j] << " | ";

		cout << "\n+-- +-- +-- +";
	}
	cout << endl;
}

bool Board::isOver() const
{
	//checking the win for both diagonal
	if (array[0][0] == 'X' || array[0][0] == 'O')
		if (array[0][0] == array[1][1] && array[0][0] == array[2][2])
			return true;

	if (array[0][2] == 'X' || array[0][2] == 'O')
		if (array[0][2] == array[1][1] && array[0][2] == array[2][0])
			return true;


	for (int i = 0; i < ROW_NUM; i++)
	{

		if (array[i][0] == 'X' || array[i][0] == 'O')
		{
			if (array[i][0] == array[i][1] && array[i][0] == array[i][2])
				return true;
		}

		if (array[0][i] == 'X' || array[0][i] == 'O')
		{
			if (array[0][i] == array[1][i] && array[0][i] == array[2][i])
				return true;
		}
	}



	return false;
}

bool Board::isDraw() const
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
			if (array[i][j] == ' ')
				return false;
	}

	return true;
}

bool Board::Empty(const Position& P) const
{
	if (array[P.row][P.column] == ' ')
		return true;

	return false;
}