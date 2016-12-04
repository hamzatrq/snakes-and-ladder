#pragma once
#include <iostream>
#include "bag.h"
#include "cell.h"

using namespace std;

class player
{
	Bag bag;
	int points;
	int posx, posy;
	int inprison;
public:
	player()
	{
		posx = posy = points = 0;
		inprison = 0;
	}

	void updateStatus(cell item)
	{

		// Updating points
		if (item.obj == 1)
		{
			points += item.quantity * 10;
		}
		else if (item.obj == 2)
		{
			points += item.quantity * 5;
		}
		else if (item.obj == 3)
		{
			points += item.quantity * 50;
		}
		else if (item.obj == 6)
		{
			cout << "Woops You are in jail. Do you want to give a bribe? Press Y or N: ";
			char x;
			cin >> x;
			if (x == 'Y')
			{
				cout << "Currently you have " << bag.getQuantity(1) << " gold coins, " << bag.getQuantity(2) << " silver coins and "<< bag.getQuantity(3) << " diamons left\n";
				cout << "Press 1 for gold, 2 for silver or 3 for diamond\t";
				cin >> x;
				if (x == '1')
				{
					if (bag.getQuantity(1) >= 3)
					{
						bag.redeemItem(1, 3);
						points -= 30;
						return;
					}
					else
					{
						cout << "You do not have enough coins.";
					}
				}
				else if(x == '2')
				{
					if (bag.getQuantity(2) >= 6)
					{
						bag.redeemItem(2, 6);
						points -= 30;
						return;
					}
					else
					{
						cout << "You do not have enough silver coins.";
					}
				}
				else
				{
					if (bag.getQuantity(3))
					{
						bag.redeemItem(3, 1);
						points -= 50;
						return;
					}
					else
					{
						cout << "You do not have any diamond.";
					}
				}
			}

			points += item.quantity * (-20);
			inprison = 3;
		}
		
		// Storing in bag if item is storable
		
		if (item.obj > 0 && item.obj < 6)
		{
			bag.insertItem(item.obj, item.quantity);
		}
		else if (item.obj == 7)
		{
			cout << "Woops There's a snake. Do you want to use an item? Press Y or N";
			char x;
			cin >> x;
			if (x == 'Y')
			{
				cout << "Currently you have " << bag.getQuantity(4) << " swords and " << bag.getQuantity(5) << " shields left\n";
				cout << "Press 1 for sword or 2 for shield\t";
				cin >> x;
				if (x == '1')
				{
					if (bag.getQuantity(4))
					{
						bag.redeemItem(4, 1);
						return;
					}
					else
					{
						cout << "You do not have a sword.";
					}
				}
				else
				{
					if (bag.getQuantity(5))
					{
						bag.redeemItem(5, 1);
						return;
					}
					else
					{
						cout << "You do not have a shield.";
					}
				}
			}

				posx = item.col;
				posy = item.row;
		}
		else if (item.obj == 8)
		{
			posx = item.col;
			posy = item.row;
		}
	}

	void updatePosition(int i, int j)
	{
		if (!inprison)
		{
			posx = i;
			posy = j;
		}
		else
			inprison--;
	}

	int getX()
	{
		return posx;
	}
	int getY()
	{
		return posy;
	}
	int getPoints()
	{
		return points;
	}
};