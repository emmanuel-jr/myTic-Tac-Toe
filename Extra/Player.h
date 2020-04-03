#pragma once
#include "Board.h"

class Player
{
private:
	char pSymbol;

public:
	Player();
	Player(const Player& p);
	virtual ~Player();
	char getInput() const;
	void setInput(char Char);
	virtual Position nextMove(const Board& board) = 0;
};

class PlayerHuman : public Player
{
public:
	PlayerHuman();
	PlayerHuman(const PlayerHuman& pp);
	virtual PlayerHuman operator=(const PlayerHuman& p);
	virtual ~PlayerHuman();
	virtual Position nextMove(const Board& board);
	bool isValid(const Board& board, const Position& pos) const;
};

class PlayerRandom : public Player
{
public:
	PlayerRandom();
	PlayerRandom(const PlayerRandom& ppp);
	virtual PlayerRandom operator=(const PlayerRandom& p);
	virtual ~PlayerRandom();
	bool isValid(const Board& board, const Position& pos) const;
	virtual Position nextMove(const Board& board);
};