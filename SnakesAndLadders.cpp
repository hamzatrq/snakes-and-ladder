#include "SnakesAndLadders.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;


/*---------------------------------------------------------------------------------------------------------------
						PUBLIC FUNCTIONS FOR THE BASE CLASS OF SNAKES AND LADDERS
---------------------------------------------------------------------------------------------------------------*/

// CONSTRUCTOR FOR THE BOARD THAT TAKES IN THE SIZE OF BOARD AND GENERATES IT DYNAMICALLY AND THEN CALL THE BOOTSTRAP FUNCTION
SnakesAndLadders::SnakesAndLadders(int boardsize)
{
	srand(time(NULL));

	board = new cell* [boardsize] {};

	for (int i = 0; i < boardsize; i++)
	{
		board[i] = new cell[boardsize]{};
	}

	turn = 0;
	ended = 0;
	size = boardsize;

	bootstrap();
}

int SnakesAndLadders::rolldiece()
{
	int n = d.rolldice();

	cout << "DICE:	" << n << endl;
	system("pause");
	player * p;
	if (turn == 0)
		p = &p1;
	else
		p = &p2;
	int j = (p->getY() + n) % size;
	int i = p->getX();
	if (p->getY() > j)
	{
		i++;
	}

	if (i*size + j < size*size)
	{
		p->updatePosition(i, j);
		p->updateStatus(board[i][j]);
		board[i][j].obj = 0;
	}

	if (i == size - 1 && j == size - 1)
	{
		ended = true;
	}
	return n;
}

void SnakesAndLadders::printboard()
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << endl;
		for (int j = 0; j < size; j++)
		{
			if (i == p1.getX() && j == p1.getY() && !turn)
			{
				cout << " P1";
			}
			else if (i == p2.getX() && j == p2.getY() && turn)
			{
				cout << " P2";
			}
			else if (board[i][j].obj == 0)
			{
				if (i*size + j + 1 < 10)
				{
					cout << " 0" << i*size + j + 1;
				}
				else
				{
					cout << " " << i*size + j + 1;
				}
			}
			else if (board[i][j].obj == 1)
			{
				cout << " GC";
			}
			else if (board[i][j].obj == 2)
			{
				cout << " SC";
			}
			else if (board[i][j].obj == 3)
			{
				cout << " DD";
			}
			else if (board[i][j].obj == 4)
			{
				cout << " SW";
			}
			else if (board[i][j].obj == 5)
			{
				cout << " SH";
			}
			else if (board[i][j].obj == 6)
			{
				cout << " PC";
			}
			else if (board[i][j].obj == 7)
			{
				cout << " SN";
			}
			else if (board[i][j].obj == 2)
			{
				cout << " LD";
			}

		}
	}
}

int SnakesAndLadders::won()
{
	if (ended)
	{
		if (p1.getPoints() > p2.getPoints())
		{
			return 1;
		}
		else if (p1.getPoints() < p2.getPoints())
			return 2;
		else
			return 3;
	}
	return 0;
}

bool SnakesAndLadders::getturn()
{
	return turn;
}

void SnakesAndLadders::changeturn()
{
	turn = !turn;
}

int SnakesAndLadders::getpoints(int p)
{
	if (p == 1)
	{
		return p1.getPoints();
	}
	else
	{
		return p2.getPoints();
	}
	return 0;
}


SnakesAndLadders::~SnakesAndLadders()
{
}


/*---------------------------------------------------------------------------------------------------------------
						 PRIVATE FUNCTIONS FOR THE BASE CLASS OF SNAKES AND LADDERS
---------------------------------------------------------------------------------------------------------------*/

// BOOTSTRAP FUNCTION IS RESPONSIBLE FOR PLACING RANDOM OBJECTS AT DIFFERENT CELLS ON BOARD
// IT IS NOT RESPONSIBLE FOR THE AMOUNT OF OBJECT IN CASE OF COINS. COINS ARE RANDOMLY GIVIEN WHEN PLAYER COMES TO THAT CELL
void SnakesAndLadders::bootstrap()
{
	int objs = rand() % (size + 1) + size;
	int i = 0;
	while (i < objs)
	{
		int row = rand() % (size - 2) + 1;
		int col = rand() % (size - 2) + 1;
		int item = 0;

		if (board[row][col].obj == 0)
		{
			item = 1 + (rand() % 6);		// 1-6 means some item
			board[row][col].obj = item;
			i++;
		}

		if (item == 1)
		{
			board[row][col].quantity = rand() % 3 + 1;
		}
		else if (item == 2)
		{
			board[row][col].quantity = rand() % 6 + 1;
		}
		else if (item == 7)
		{
			board[row][col].col = rand() % size;
			board[row][col].row = rand() % row;
		}
		else if (item == 8)
		{
			board[row][col].col = rand() % size;
			board[row][col].row = rand() % (size - row) + row;
		}

		if (item > 2)
		{
			board[row][col].quantity = 1;
		}

	}
}
