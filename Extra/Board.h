#pragma once

const int ROW_NUM = 3;
const int COL_NUM = 3;

struct Position
{
	int column;
	int row;
};

class Board
{
	Position position;
	char array[ROW_NUM][COL_NUM];
	void copy(const Board& to_copy);

public:
	Board();
	Board(const Board& to_copy);
	~Board();
	Board operator=(const Board& to_copy);
	char getSymbol(Position pos) const;
	void setSymbol(Position pos, char symbol);
	bool Empty(const Position& P) const;
	void print() const;
	bool isOver() const;
	bool isDraw() const;
};