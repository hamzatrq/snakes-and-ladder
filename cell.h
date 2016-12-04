#pragma once
//	-------------------	REFRENCE TO OBJ IN CELL STRUCT ----------------------

/*
	0 means there is nothing on that cell
	1 means Gold coins	number of gold coins will be random but max 3
	2 means Silver coins number of silver coins will be random but max 6
	3 means a Diamond
	4 means a Sword
	5 means a Shield
	6 means a Prison cell
	7 means a Snake
	8 means a Ladder
*/

struct cell
{
	int obj;
	int quantity; // Only for coins

				  // If its a ladder or snake then the cell to where it goes
	int row; int col;

	cell()
	{
		obj = quantity = row = col = 0; // By default everything is 0
	}
};
