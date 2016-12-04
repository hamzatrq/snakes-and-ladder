#include <iostream>
#include "SnakesAndLadders.h"
#include <Windows.h>

using namespace std;

void print(SnakesAndLadders &game)
{
	system("cls");
	if (!game.getturn())
		cout << "PLAYER 1 TURN";
	else
		cout << "PLAYER 2 TURN";
	game.printboard();
}

int main() {
	int size;
	cout << "Enter the size of board:	";
	cin >> size;

	if (size < 5 || size > 50)
	{
		cout << "Please enter a valid size.\n";
		return 0;
	}

	SnakesAndLadders game(size);

	bool p = false;

	while (!game.won())
	{
		print(game);
		cout << "\nRoll The Dice Now!\n";
		system("pause");
		for (int i = 0; i < 10; i++)
		{
			print(game);
			cout << "\nRoll The Dice Now!\n";
			cout << "DICE:	" << 1 + rand() % 6 << endl;
			Sleep(50);
		}
		print(game);
		cout << "\nRoll The Dice Now!\n";
		game.rolldiece();
		print(game);
		cout << "\n\n" << "Points:\n" << "Player 1:\t"
			<< game.getpoints(1) << "\nPlayer 2:\t"
			<< game.getpoints(2)
			<< "\n\n\nTime To Change The Turn." << endl;
		system("pause");
		game.changeturn();
	}

	system("cls");

	if (game.won() == 1)
	{
		cout << "PLAYER 1 WON";
	}
	else if (game.won() == 2)
	{
		cout << "PLAYER 2 WON";
	}
	else
	{
		cout << "ITS A DRAW";
	}

	cout << endl;
	return 0;
}