#pragma once

class Bag
{
	int items[5];
public:
	Bag()
	{
		for (int i = 0; i < 5; i++)
		{
			items[i] = 0;
		}
	}
	void insertItem(int itemcode, int quantity)
	{
		items[itemcode - 1] += quantity;
	}

	int getQuantity(int itemcode)
	{
			return items[itemcode - 1];
	}

	void redeemItem(int itemcode, int quantity)
	{
			items[itemcode -1 ] -= quantity;
	}
};