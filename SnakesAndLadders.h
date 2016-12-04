#pragma once
#include "cell.h"
#include "player.h"
#include "dice.h"

class SnakesAndLadders
{
public:
	SnakesAndLadders(int);
	int rolldiece();
	~SnakesAndLadders();
	void printboard();
	int won();
	bool getturn();
	void changeturn();
	int getpoints(int);
private:
	cell **board;
	dice d;
	player p1, p2;
	bool turn;
	int size; // size represents the size of number of rows or column as both are same.
	void bootstrap();
	bool ended;
};
