/*
   Name: Emmanuel Idun
   Student #: 200418000
   Program: CS 210-001
   Assignment # 2

   Extra feature: creates two subfunctions; gameOn and winTie which are just called in the main function.
                  In th winTie, when the game is a tie, the user is asked if he/she wants to continue or end the game and implement as required

*/

#include "Player.h"
#include <iostream>
using namespace std;

void gameOn(Board& b, char Symbol, Player* p1, Player* p2)
{
	do
	{
		cout << "Player 1's turn\n";
		Position pos;
		pos = p1->nextMove(b);
		Symbol = 'X';
		b.setSymbol(pos, Symbol);

		if (!b.isOver() && !b.isDraw())
		{
			cout << "Player 2's turn\n";
			pos = p2->nextMove(b);
			Symbol = 'O';
			b.setSymbol(pos, Symbol);
		}

		else
			break;

	} while (!b.isOver() && !b.isDraw());
}


void winTie(Board& b, char Symbol, Player* p1, Player* p2)
{
	b.print();

	if (b.isOver())
	{

		if (Symbol == 'X')
			cout << "Congrats Player 1, you win!" << endl;
		else
			cout << "Congrats Player 2, you win!" << endl;
	}

	else
	{
		char ans;

		cout << "It's a tie!" << endl;
		cout << "\nIf you wish to continue, enter 'y'. If not, enter 'n'" << endl;
		cin >> ans;

		if (ans == 'y')
		{
			Board newB;
			gameOn(newB, Symbol, p1, p2);
		}

		else
			cout << "Game ended" << endl;
		return;
	}
}


int main()
{
	char Symbol = 'X';
	char player1, player2;

	cout << "*******************************************************" << endl;
	cout << "h: Human\n";
	cout << "c: Computer\n";
	cout << "*******************************************************" << endl << endl;
	cout << "Player 1 is ";
	cin >> player1;
	cout << "Player 2 is ";
	cin >> player2;

	Board b;
	
	if (player1 == 'h' && player2 == 'h')
	{
		Player* p1 = new PlayerHuman;
		Player* p2 = new PlayerHuman;

		gameOn(b, Symbol, p1, p2);

		winTie(b, Symbol, p1, p2);
	}

	if (player1 == 'c' && player2 == 'h')
	{
		Player* p1 = new PlayerRandom;
		Player* p2 = new PlayerHuman;

		gameOn(b, Symbol, p1, p2);

		winTie(b, Symbol, p1, p2);
	}

	if (player1 == 'h' && player2 == 'c')
	{
		Player* p1 = new PlayerHuman;
		Player* p2 = new PlayerRandom;

		gameOn(b, Symbol, p1, p2);

		winTie(b, Symbol, p1, p2);
	}

	if (player1 == 'c' && player2 == 'c')
	{
		Player* p1 = new PlayerRandom;
		Player* p2 = new PlayerRandom;

		gameOn(b, Symbol, p1, p2);

		winTie(b, Symbol, p1, p2);
	}



	return 0;
}

